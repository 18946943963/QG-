import numpy as np
import sklearn.datasets as datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler


def mean_squared_error(y_true, y_predict):
    """计算y_true和y_predict之间的MSE"""
    return np.sum((y_true - y_predict) ** 2) / len(y_true)


class LinearRegression:

    def __init__(self):
        """初始化Linear Regression模型"""
        self.w_matrix = None

    def fit_normal(self, x_train, y_train):
        """根据训练数据集X_train, y_train训练Linear Regression模型"""
        x_b = np.hstack([np.ones((len(x_train), 1)), x_train])
        self.w_matrix = np.linalg.inv(x_b.T.dot(x_b)).dot(x_b.T).dot(y_train)

        return self

    def fit_gd(self, x_train, y_train, eta=0.01, n_iters=1e4):
        """根据训练数据集X_train, y_train, 使用梯度下降法训练Linear Regression模型"""

        def mse_test(theta, x_b, y):
                return np.sum((y - x_b.dot(theta)) ** 2) / len(y)

        def train_w(theta, x_b, y):
            return x_b.T.dot(x_b.dot(theta) - y) * 2. / len(y)

        def gradient_descent(x_b, y, initial_w, eta, n_iters=1e4, epsilon=1e-8):
            """梯度下降法"""
            w = initial_w
            cur_iter = 0

            while cur_iter < n_iters:
                gradient = train_w(w, x_b, y)   #  对w的导数
                last_theta = w
                w = w - eta * gradient          #   训练w
                if (abs(mse_test(w, x_b, y) -
                        mse_test(last_theta, x_b, y))
                        < epsilon):
                    break

                cur_iter += 1

            return w

        x_b = np.hstack([np.ones((len(x_train), 1)), x_train])
        initial_w = np.zeros(x_b.shape[1])
        self.w_matrix = gradient_descent(x_b, y_train, initial_w, eta, n_iters)

        return self

    def predict(self, x_predict):
        """给定待预测数据集X_predict，返回表示X_predict的结果向量"""
        x_b = np.hstack([np.ones((len(x_predict), 1)), x_predict])
        return x_b.dot(self.w_matrix)

    def score(self, x_test, y_test):
        """根据测试数据集 X_test 和 y_test 确定当前模型的准确度"""

        y_predict = self.predict(x_test)
        return mean_squared_error(y_test, y_predict)

    def __repr__(self):
        return "LinearRegression()"


boston_data = datasets.load_boston()
x = boston_data['data']  # total x size (506,)
y = boston_data['target']  # total y size (506,)
# keep data with target value less than 50.
x = x[y < 50]  # total x size (490,)
y = y[y < 50]  # total x size (490,)

# notice! need data normalize
scaler = StandardScaler().fit(x)
x = scaler.transform(x)

# 训练数:(343,) 测试数:(147,)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=123)

regs = LinearRegression()
regs.fit_gd(x_train, y_train)

mse = regs.score(x_test, y_test)

print('Mean squared error:%.2f' % mse)
