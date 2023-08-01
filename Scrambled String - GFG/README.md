# Scrambled String
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two strings&nbsp;<strong>S1</strong>&nbsp;and&nbsp;<strong>S2</strong>&nbsp;of equal length, the task is to determine if S2 is a scrambled form of S1.</span></p>
<p><span style="font-size: 18px;"><strong>Scrambled string:</strong>&nbsp;Given string&nbsp;<strong>str</strong>, we can represent it as a binary tree&nbsp;by partitioning it into two non-empty substrings recursively.<br>Below is one possible representation of str = <strong>coder:</strong><br>&nbsp;</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/707514/Web/Other/5360f3bd-09bb-4f9d-9c84-be3844091359_1685087790.png"><br><span style="font-size: 18px;">To scramble the string, we may choose any non-leaf node and swap its two children.&nbsp;<br>Suppose, we choose the node <strong>co</strong> and swap its two children, it produces a scrambled string <strong>ocder</strong>.<br>Similarly, if we continue to swap the children of nodes <strong>der</strong> and <strong>er</strong>, it produces a scrambled string <strong>ocred</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong>&nbsp;Scrambled string is not the same as an Anagram.</span></p>
<p><span style="font-size: 18px;">Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> S1="coder", S2="ocder"
<strong>Output:</strong> Yes
<strong>Explanation:</strong> ocder is a scrambled 
form of coder.

    ocder
   /    \
  oc    der
 / \    
o   c  

As "ocder" can represent it 
as a binary tree by partitioning 
it into two non-empty substrings.
We just have to swap 'o' and 'c' 
to get "coder".</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> S1="abcde", S2="caebd" 
<strong>Output:</strong> No
<strong>Explanation:</strong> caebd is not a 
scrambled form of abcde.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything.&nbsp;You only need to complete the function<strong>&nbsp;isScramble</strong><strong>()&nbsp;</strong>which takes two strings S1 and S2&nbsp;as input and returns a boolean value.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(N<sup>2</sup>)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(N<sup>2</sup>)</span></p>
<p><strong><span style="font-size: 18px;">Constrains:&nbsp;</span></strong></p>
<ul>
<li><span style="font-size: 18px;">S1.length = S2.length</span></li>
<li><span style="font-size: 18px;">S1.length&lt;=31</span></li>
<li><span style="font-size: 18px;">S1 and S2 consist of lower-case English letters.</span></li>
</ul></div>