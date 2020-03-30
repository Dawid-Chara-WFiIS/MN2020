import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns

sns.set_style('whitegrid')
data = pd.read_csv("results.csv")

plt.plot(data.iloc[:, 0], data.iloc[:, 1])
plt.xlabel("Czas [s]")
plt.ylabel("Wychylenie z położenia równowagi [m]")
plt.savefig("result.png")
plt.show()
