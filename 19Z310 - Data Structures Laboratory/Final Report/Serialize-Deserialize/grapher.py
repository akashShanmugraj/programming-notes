import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a Pandas DataFrame
df = pd.read_csv('./benchmarks.csv')

plt.figure(figsize=(8, 6))
plt.scatter(df['Testcase Size'], df['Runtime'], alpha=0.5)
plt.xlabel('Size of Array')
plt.ylabel('Runtime')
plt.title('Serialize and Deserialize a Binary Tree')
plt.grid(True)
plt.show()

avg_runtime = df.groupby('Testcase Size')['Runtime'].mean().reset_index()

# Create a line graph for Testcase Size vs Average Runtime
plt.figure(figsize=(10, 6))
plt.plot(avg_runtime['Testcase Size'], avg_runtime['Runtime'], marker='o', linestyle='-', color='b')
plt.xlabel('Testcase Size')
plt.ylabel('Average Runtime (seconds)')
plt.title('Average Runtime vs Testcase Size')
plt.grid(True)
plt.show()

# Calculate and display the overall average runtime
overall_avg_runtime = df['Runtime'].mean()
print(f"Overall Average Runtime: {overall_avg_runtime:.6f} seconds")

# Create a bar graph for Testcase Size vs Average Runtime
plt.figure(figsize=(10, 6))
plt.bar(avg_runtime['Testcase Size'], avg_runtime['Runtime'], color='b')
plt.xlabel('Testcase Size')
plt.ylabel('Average Runtime (seconds)')
plt.title('Average Runtime vs Testcase Size')
plt.grid(True)
plt.show()

# Calculate and display the overall average runtime
overall_avg_runtime = df['Runtime'].mean()
print(f"Overall Average Runtime: {overall_avg_runtime:.6f} seconds")