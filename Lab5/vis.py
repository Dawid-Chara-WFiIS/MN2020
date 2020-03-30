import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd

sns.set_style("whitegrid")
data = pd.read_csv("eigenvectors.csv")
X = np.linspace(-5, 5, 998)
plt.figure(figsize=(15, 10))
sns.lineplot(X, data.iloc[:, 0], label="1")
sns.lineplot(X, data.iloc[:, 1], label="2")
sns.lineplot(X, data.iloc[:, 2], label="3")
sns.lineplot(X, data.iloc[:, 3], label="4")
sns.lineplot(X, data.iloc[:, 4], label="5")

plt.xlim(-5, 5)
plt.title("Wave funtions on [-5, 5]")
plt.xlabel("Argument")
plt.ylabel("Value")
plt.savefig("result.png")
plt.show()
