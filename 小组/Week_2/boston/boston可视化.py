from sklearn.datasets import load_boston
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt

#   加载数据
housing = load_boston()
X = housing.data
y = housing.target

#   将数据写入df里
df = pd.DataFrame()
for i in range(X.shape[1]):
    df[housing.feature_names[i]]=X[:, i]
df['target'] = y

#   预处理
df.dropna(axis=0, inplace=True)

#   数据分析
print(df.describe())

#   获取列标签
column_headers = list(df.columns.values)

plt.figure(figsize=(8, 8))

for i in range(13):
    plt.subplot(4, 4, i+1)
    plt.scatter(X[:, i], y, s=5)
    plt.xlabel(column_headers[i])
    plt.ylabel('Price')
    plt.title(str(i+1)+'. '+column_headers[i]+' - Price')

plt.tight_layout(rect=[0, 0, 1, 0.95])
plt.suptitle('各属性与房价之间的关系')
plt.show()

