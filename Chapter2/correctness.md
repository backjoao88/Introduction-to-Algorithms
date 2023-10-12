## Algorithms Correctness and Time Complexity

<b> How do we prove that an algorithm is correct? </b>

<p>That's the base question that we do when talk about software quality. This is a question that we do because we need to find a way to trust on the solution that we came up to. There are a few ways to prove that a solution is correct:</p>

- Persuasive talks (using arguments to prove)

- Tests (experimental)

- Scientific proof (generally by math induction)

<p>Generally the best option is to use a combination between these three. But what's a proof?</p>

### Mathematical Induction

<p>A proof is something that can cause in the public a certainty that something is correct. Generally, in a mathematical induction, we have to first prove a basis case, and then define an induction base, what's out **hypotesis**. The first case is calculated, and the rest makes part of a repetitive proccess.

1. Base: Proof P(1)
2. Hypotesis: Proof P(2), Proof P(3), Proof P(4), Proof P(K-1)
3. Step: Proof(K)

<p>We can use the above algorithm to prove the correctness of other algorithms. For that, we have to assume that this algorithm is an axiom (always work)</p>

### Correctness

```
function mult(y,z):
    x = 0
    while(z>0):
        if(z mod 2 != 0):
            x = x + y
        y = 2*y
        z = int(z/2)
    return z
```
<b>Invariant:</b> y<sub>j</sub>z<sub>j</sub>+x<sub>j</sub> = y<sub>0</sub>z<sub>0</sub> (the y<sub>0</sub>z<sub>0</sub> are the parameters of the function in this mathematical formula)

<b>Basis</b>: y<sub>0</sub>z<sub>0</sub> + x<sub>0</sub> = y<sub>0</sub>z<sub>0</sub> (checked, because x<sub>0</sub> is zero at the beginning)

<b>Hypotesis</b>: y<sub>j</sub>z<sub>j</sub>+x<sub>j</sub> = y<sub>0</sub>z<sub>0</sub>

<b>Step</b>: y<sub>j+1</sub>z<sub>j+1</sub>+x<sub>j+1</sub> = y<sub>0</sub>z<sub>0</sub> (we got to proof that the first sentence reach to the last one, doing that, we would proof the algorithm correctness).

<b> How do i know that an algorithm is fast? </b>

To check if an algorithm is fast, we can use the natural way of doing it: counting the number of the operations. For example, suppose the <i>Seletion Sort</i> algorithm below:

```
function seletionSort(A[0..n]):
    for i=1 to n-1:
        minor = i
        for j=i+1 to n:
            if A[minor] > A[j]:
                minor = j
        Swap(A, i, minor)
```

To count the number of operations, we have to consider the for <i>n loop</i> which and choose one operation (in this case, the <i>if operation</i>). For example, in the outer for loop when the i = 3, the if operation is executed n-4 times. When it's i=4, the if operation is executed n-5 times and so on, until i reach n.

These kinds of analysis depends on the computational model that you're using, so, we can use different computational models to solve different problems (Need to define what is a computational step or instruction). For computational models, the computability (set of problemas that it can solve) is equal, but the complexity is different. In the most cases, the analysis is based on the RAM model, where arithmetic/logical/attribution operations and others are <b>constant</b>.
