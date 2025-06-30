# Week 1 - Competitive Programming Journal

## Getting Back on Track

Previously, I solved some Codeforces problems and participated in a few contests without a clear plan. As a result, my performance dropped significantly.

Now, I'm starting over with a serious mindset. I already have a basic understanding of STL, which should help me as I resume my CP journey.

## This Week's Focus

I'm solving B-level problems on Codeforces using the following sheet:

🔗 [Problem Sheet](https://docs.google.com/spreadsheets/d/1gg2QxRIYmzjznPZGTcVUZ0hso3Ix_T9vw7CMSnVcGo0/edit?usp=sharing)

You can track which problems I've solved there.

## Notes

- No fixed topic this week — solving problems randomly from the sheet  
- Rebuilding speed and problem-solving mindset  
- Listing resources and deeper learnings as I move forward  

## Thoughts on Good Problems

I'll be using this section to highlight and reflect on problems that stood out — whether because of their elegance, a neat trick, or a good learning opportunity.

### 🟢 [Bear and Finding Criminals (Codeforces 680B)](https://codeforces.com/contest/680/problem/B)

This is a simple and intuitive two-pointers problem that's great for beginners. It helps build logic for symmetric traversal and boundary checking. I recommend this as a warm-up for those getting back into CP or starting out with problem-solving strategies.

### 🟢 [Petr and a Combination Lock (Codeforces 1097B)](https://codeforces.com/problemset/problem/1097/B)

This is a classic example of using **bitmasking** or **bitwise enumeration** to check all possible combinations. The core idea is to try every subset of directions by rotating left or right and checking if the total angle sums to a multiple of 360°. It's a clever brute-force problem that teaches how bitwise operations can be useful when you need to explore all possible configurations efficiently.

### 🟢 [Good Start (Codeforces 2113B)](https://codeforces.com/contest/2113/problem/B)

This was a good problem for practicing careful case analysis. It requires recognizing and handling all the necessary scenarios thoughtfully, which makes it a great problem for improving attention to detail and logical completeness.

📷 **[View Diagram/Image Explanation](https://github.com/aorko01/competitive-programming-journal/blob/main/problems/month_1/week_1/Good_problems/photo_2025-06-19_21-52-08.jpg)**  
🧠 You can refer to this image along with the tutorial to better understand the structure of the problem and its cases.

### 🟢 [Racing (Codeforces 2110C)](https://codeforces.com/contest/2110/problem/C)

This problem involves simulating the evolution of valid height ranges under directional constraints given by an array `d[]`, where each value is -1, 0, or 1. You must assign heights such that each move conforms to the `d[i]` constraint.

📷 **[View Diagram/Image Explanation](https://github.com/aorko01/competitive-programming-journal/blob/main/problems/month_1/week_1/Good_problems/Pasted%20image.png)** 🧠 **Brief Explanation**:
* **White**: Original heights
* **Blue**: Valid ranges based on `d[i]`
* **Purple**: Overlaps (intersection) between expected and valid heights
* **Yellow**: One valid reconstruction path

The key idea:
* Maintain a valid height range `[l, r]` that evolves step by step based on the value of `d[i]`.
   * If `d[i] = -1`, next valid range is `[l, r-1]`
   * If `d[i] = 0`, next valid range is `[l, r]`
   * If `d[i] = 1`, next valid range is `[l+1, r]`

If at any point the actual height lies outside this valid range, the answer is -1.

🔍 The subtle trick is: When choosing the final height, always pick the **maximum possible valid value**, because backtracking (like going down when `d[i] = -1`) may not be possible otherwise — especially if we chose a smaller height earlier.

### 🟢 [Ugly Number III (LeetCode 1201)](https://leetcode.com/problems/ugly-number-iii/)

This is an excellent problem that combines **binary search** with the **inclusion-exclusion principle**. The goal is to find the nth ugly number that is divisible by at least one of three given numbers (a, b, c).

🧠 **Key Insights**:
* Use binary search on the answer space to find the nth ugly number
* For a given number `x`, count how many ugly numbers ≤ x exist using inclusion-exclusion:
  * Count = `x/a + x/b + x/c - x/lcm(a,b) - x/lcm(b,c) - x/lcm(a,c) + x/lcm(a,b,c)`
* Binary search finds the smallest number where this count ≥ n

This problem is a great example of how mathematical principles can optimize what would otherwise be a brute-force approach. It's particularly valuable for understanding how to apply inclusion-exclusion in competitive programming contexts.


> I'll continue adding good problems like this in the README to help others discover valuable practice problems.