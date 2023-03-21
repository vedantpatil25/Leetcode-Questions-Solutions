# Mean of range in array
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of <strong>n</strong> integers and <strong>q</strong> queries. Write a program to find floor value of mean in range <strong>l</strong> to <strong>r </strong>for each query in a new line.<br>
Queries are given by an array queries[] of size 2*q. Here queries[2*i] denote l and queries[2*i+1] denote r for i-th query (0&lt;= i &lt;q).</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> Arr[] = {1, 2, 3, 4, 5}, Q = 3
queries[] = {0, 2, 1, 3, 0, 4}
<strong>Output :</strong> 2 3 3
<strong>Explanation:
</strong>Here we can see that the array of 
integers is [1, 2, 3, 4, 5].
<strong>Query 1:</strong> L = 0 and R = 2
Sum = 6
Integer Count = 3
So, Mean is 2
<strong>Query 2:</strong> L = 1 and R = 3
Sum = 9
Integer Count = 3
So, Mean is 3
<strong>Query 3:</strong> L = 0 and R = 4
Sum = 15
Integer Count = 5
So, the Mean is 3.
So, In the end, the function will 
return the array [2, 3, 3] as an answer.
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> Arr[] = {6, 7, 8, 10}, Q = 2
queries[] = {0, 3, 1, 2}
<strong>Output :</strong> 7 7
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>findMean() </strong>that takes an&nbsp;<em>array (<strong>arr</strong>)</em><strong>, </strong>an array of queries (<strong>queries</strong>),<strong>&nbsp;</strong><em>sizeOfArray (<strong>n</strong>)</em><strong>, </strong><em>sizeOfQueriesArray<strong><em> </em></strong>(</em><strong><em>2*q</em></strong><em>)</em>&nbsp;and return the array of size <strong>q&nbsp;</strong>which has the answer for all the queries. The<strong> driver code </strong>takes care of the <strong>printing</strong>.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(q + n).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(n).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong>&nbsp;<br>
1 ≤ q,n ≤ 2*10<sup>5</sup><br>
1 ≤ a[i] ≤ 10<sup>3</sup></span></p>
</div>