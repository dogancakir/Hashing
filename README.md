    1. INTRODUCTION
In this assignment, a company wants to store the records of their customers in a hash 
table. In order to decide on a suitable hashing strategy, they want to analyze the performance of different hashing strategies. The company wants to operate four operations, insert, delete, update and search.

       There are 4 types of hashing. 
    a. Linear Probing
ℎ(𝑘, i) = (𝑘+i) 𝑚𝑜d 𝑚 and  i ∈ [0, 𝑚−1];

    b. Double Hashing
ℎ(𝑘, i) = (ℎ1 (𝑘) + i∗ℎ2 (𝑘)) 𝑚𝑜d 𝑚 and i ∈ [0, 𝑚−1]
ℎ1 (𝑘) = 𝑘 𝑚𝑜d 𝑚  and ℎ2 (𝑘) = 1 + 𝑘 𝑚𝑜d(𝑚−1)

    c. Quadratic Hashing
ℎ(𝑘, i) = (ℎ′(𝑘) + 𝑐1 i+ 𝑐2 i2) mod m  and i ∈ [0, 𝑚−1]
ℎ′(𝑘) = 𝑘 𝑚𝑜d 𝑚

    d. Universal Hashing
h=(k1*a1+k2*a2+k3*a3)mod m
k1,k2,k3 are segments of our key and a1,a2,a3 are random numbers.
For second step of Universal Hashing, I use Linear Probabing and new solution is
k(h,i)=(h+i) 𝑚𝑜d 𝑚 and  i ∈ [0, 𝑚−1];

    2. VARIABLES
There is a Hash class holds idNumber and deleted as attribute. In constructor of Hash class, idNumber and deleted values are equaled to 0.

int idNumber: It holds keys from file.
int deleted: Holds -1(if slot is deleted),0(slot is empty) or 1(slot is full).
int collision:holds collisions
int removeCounter: holds deleted slots in table.
char* operation: holds read operation from file
int id1,id2: holds read id’s from file. id2 is used for update operation
int M,type; M is m in assignment, type holds hashing types(1->linear,2->Double,3->Quadratic,4->Universal) 
Hash *table: our hash table

    3. ENVIRONMENT
It is written in Visual Studio and compiled in SSH.

    4. VALUES


		Linear	Quadratic	Double	Universal
m=1327	1434	1108		1530		421
M=2657	545		507			547			232
