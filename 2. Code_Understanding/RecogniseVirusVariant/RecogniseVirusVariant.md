# Problem Discription
The virus data B[] is located in data set A[].
Original program recognises the B[] within A[] becomparing each byte element in A[] from B[]. For examp: A[]={2,3,4,8,5,8,4,8,5} and B[]={4,8,5}
Now the virus has variants:
- Variant[] could be any order of B[]. For example B[]={4,8,5} => V[]={5,8,4};
- Variant[] could be subtraction/Addition of B[]. For example  B[]={4,8,5} => V[]={5,9,6};
- Variant[] could be subtraction/Addition after reorder of B[]. For example: B[]={4,8,5} => V[]={6,9,5};

* **Input**
  - On the first line, the number of executable code data N and the number of virus data M separated by a black are inputted.  `(1<=N<=20000>) and (1<=M<=10)`
  - On the second line, N executable code data Ai separated by a blank are inputted.
  - On the third line, M virus data Bi separate by a blank are inputted. (1<=Bo<=100>)
* **Output**
  - A number of viruses are outputted.
## Approach
* sort the data set `A[]`. 
* use 1 for loop `from i = 0 to i = length M of original virus `, to make comparision of virus and data set `A[]`, elements by elements. 
* if it is a variant => the different between variant and virus is the same as `change = data - original virus`