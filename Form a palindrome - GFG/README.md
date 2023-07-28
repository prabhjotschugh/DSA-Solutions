# Form a palindrome
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string, find the minimum number of characters to be inserted to convert it to palindrome.<br>
For Example:<br>
ab: Number of insertions required is 1.&nbsp;<strong>b</strong>ab or aba<br>
aa: Number of insertions required is 0. aa<br>
abcd: Number of insertions required is 3.&nbsp;<strong>dcb</strong>abcd</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> str = "abcd"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Inserted character marked
with bold characters in <strong>dcb</strong>abcd
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> str = "aa"
<strong>Output:</strong> 0
<strong>Explanation:</strong>"aa" is already a palindrome.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>countMin()</strong>&nbsp;which takes the string <strong>str&nbsp;</strong>as inputs and returns the answer.<br>
<br>
<strong>Expected Time Complexity:</strong>&nbsp;O(N<sup>2</sup>), N = |str|<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N<sup>2</sup>)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ |str|&nbsp;≤ 10<sup>3</sup><br>
str contains only lower case alphabets.</span></p>
</div>