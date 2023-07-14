# Tree from Postorder and Inorder
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given <strong>inorder </strong>and <strong>postorder</strong> traversals of a Binary Tree in the arrays <strong>in[]</strong> and <strong>post[]</strong> respectively. The task is to construct the binary tree from these traversals.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
<strong>Output: </strong>1 2 4 8 5 3 6 7<strong>
Explanation: </strong>For the given postorder and
inorder traversal of tree the&nbsp; resultant
binary tree will be
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  1
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp; &nbsp;  \
&nbsp;&nbsp;&nbsp;&nbsp; 2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;  3
&nbsp;&nbsp; /&nbsp; \      /  \
&nbsp; 4&nbsp;&nbsp;&nbsp; 5&nbsp;&nbsp;  6&nbsp;&nbsp;&nbsp; 7
&nbsp;&nbsp;&nbsp;\
&nbsp;&nbsp;&nbsp;&nbsp; 8</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
<strong>Output: </strong>2 9 5 4 3<strong>
Explanation: &nbsp;
</strong>the&nbsp; resultant binary tree will be
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;2
&nbsp; &nbsp; &nbsp; &nbsp; /&nbsp;  &nbsp; \
&nbsp; &nbsp; &nbsp;&nbsp; 9&nbsp; &nbsp; &nbsp;  4
       &nbsp;\     /
     &nbsp; &nbsp; 5   3</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything.&nbsp;Complete the function <strong>buildTree() </strong>which takes the&nbsp;inorder, postorder traversals&nbsp;and the number of nodes in the tree as input parameters&nbsp;and returns the root node of the newly constructed Binary Tree.<br>
<strong>The generated output contains the&nbsp;preorder traversal of the constructed tree.</strong></span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N<sup>2</sup>)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N &lt;= 10<sup>3</sup><br>
1 &lt;= in[i], post[i] &lt;= 10<sup>3</sup></span></p>

<p>&nbsp;</p>
</div>