# Add two numbers represented by linked lists
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two decimal numbers represented by two linked lists of size <strong>N</strong> and <strong>M </strong>respectively. The task is to return a linked list that represents the sum of these two numbers. </span></p>

<p><span style="font-size:18px">For example, the number <strong>190</strong> will be represented by the linked list, <strong>1-&gt;9-&gt;0-&gt;null, </strong>similarly <strong>25 </strong>by <strong>2-&gt;5-&gt;null. </strong>Sum of these two numbers is<strong> </strong>190 + 25 =<strong> 215, </strong>which will be represented by<strong> 2-&gt;1-&gt;5-&gt;null. </strong>You are required to return the head of the linked list<strong> 2-&gt;1-&gt;5-&gt;null.</strong></span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
<strong>Output: </strong>3 9 0&nbsp;&nbsp;<strong>
Explanation: </strong>For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list&nbsp;resultant linked
list will be (3&nbsp;9 0).</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
<strong>Output: </strong>7 0<strong>
Explanation: </strong>For the given two linked
list (6 3) and (7), after adding the
two linked list&nbsp;resultant linked list
will be (7 0).</span></pre>

<p><span style="font-size:18px"><strong>Your&nbsp;Task:</strong><br>
The task is to complete the function <strong>addTwoLists</strong>() which has node reference of both the linked lists and returns the head of the sum list. &nbsp;&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N+M)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Max(N,M)) for the resultant list.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N, M &lt;= 5000</span></p>
</div>