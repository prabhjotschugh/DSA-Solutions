# Queue using stack
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Implement a Queue&nbsp;using two stack</span><span style="font-size:18px"><strong>&nbsp;s1</strong>&nbsp;and<strong>&nbsp;s2</strong>.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>enqueue(2)
enqueue(3)
dequeue()
enqueue(4)
dequeue()<strong>
Output: </strong>2 3
<strong>Explanation:
</strong>enqueue(2)&nbsp;the queue&nbsp;will be {2}
enqueue(3)&nbsp;the queue&nbsp;will be {3 2}
dequeue() the poped element will be 2&nbsp;
the stack&nbsp;will be {3}
enqueue(4)&nbsp;the stack&nbsp;will be {4 3}
dequeue() the poped element will be 3. &nbsp;
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>enqueue(2)
dequeue()
dequeue()<strong>
Output: </strong>2 -1</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">Since this is a function problem, you don't need to take inputs. You are required to complete the two methods&nbsp;<strong>enqueue</strong><strong>()</strong>&nbsp;which takes&nbsp;an integer <strong>'x'</strong>&nbsp;as input&nbsp;denoting the element to be pushed into the queue&nbsp;and <strong>dequeue</strong><strong>()</strong>&nbsp;which returns the&nbsp;integer&nbsp;poped out from the queue.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for&nbsp;<strong>enqueue</strong><strong>()&nbsp;</strong>and O(n) for <strong>dequeue</strong><strong>()</strong><br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1) for both&nbsp;<strong>enqueue</strong><strong>()&nbsp;</strong>and <strong>dequeue</strong><strong>()</strong></span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;=<strong>&nbsp;</strong>Number of queries&nbsp;&lt;= 100<br>
1 &lt;= values of the stack&nbsp;&lt;= 100</span></p>
</div>