import numpy as np
import sklearn.datasets as datasets
from sklearn.model_selection import train_test_split
np.random.seed(123)


def mse(y_true, y_predict):
    """计算y_true和y_predict之间的MSE"""
    return np.sum((y_true - y_predict)**2) / len(y_true)


class LinearRegression:
    def __init__(self):
        self.w_matrix = None

    def fit_normal(self, x_train, y_train):
        """
        w_matrix=(X^T * X)^-1 * X^T * y
        """
        x_matrix = np.hstack([np.ones((len(x_train), 1)), x_train])
        self.w_matrix = np.linalg.inv(x_matrix.T.dot(x_matrix)).dot(x_matrix.T).dot(y_train)

    def predict(self, x_pred):
        """给定待预测数据集X_predict，返回表示X_predict的结果向量"""
        x_matrix = np.hstack([np.ones((len(x_pred), 1)), x_pred])
        return x_matrix.dot(self.w_matrix)

    def score(self, x_test, y_test):
        """
            x_test:x test data
            y_test:true label y for x test data
        """
        y_pred = self.predict(x_test)
        return mse(y_test, y_pred)


boston_data = datasets.load_boston()
x = boston_data['data']  # total x data (506,)
y = boston_data['target']
# keep data with target value less than 50.
x = x[y < 50]  # total x data (490,)
y = y[y < 50]  # total x data (490,)
x_training, x_testing, y_training, y_testing = train_test_split(x, y, test_size=0.3, random_state=123)

regs = LinearRegression()
regs.fit_normal(x_training, y_training)
mse_result = regs.score(x_testing, y_testing)

print("训练后的mse = %0.2f" % mse_result)
