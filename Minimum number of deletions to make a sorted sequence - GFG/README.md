# Minimum number of deletions to make a sorted sequence
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>arr</strong> of size <strong>N</strong>, the task is to remove or delete the minimum number of elements from the array so that when the remaining elements are placed in the same sequence order form an <strong>increasing sorted sequence</strong>.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 5, arr[] = {5, 6, 1, 7, 4}
<strong>Output:</strong> 2
<strong>Explanation</strong>: Removing <strong>1</strong> and <strong>4</strong>
leaves the remaining sequence order as
<strong>5 6 7</strong> which is a sorted sequence.</span></pre>

<div>&nbsp;</div>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input: </strong>N = 3, arr[] = {1, 1, 1}
<strong>Output: </strong>2
<strong>Explanation</strong>: Remove 2 1's
</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong><code>minDeletions</code>()&nbsp;</strong>which takes <strong>N</strong> and array <strong>arr </strong>as input parameters and returns the integer value<br>
<br>
<strong>Expected Time Complexity:</strong> O(<strong>N<sup>2</sup></strong>)<br>
<strong>Expected Auxiliary Space:</strong> O(<strong>N</strong>)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>3</sup></span></p>
</div>