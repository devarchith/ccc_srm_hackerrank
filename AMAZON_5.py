#Given a string s, return the length of the longest palindromic substring in s.

#Input Format

#The First Line contains an integer N
#The Second line contains a string of size N.
#Constraints

#1 <= s.length <= 1000
#s consist of only digits and English letters.
#Output Format

#Print the single integer which is the answer to the question

#Sample Input 0

#4
#epbm
#Sample Output 0

#1
#Sample Input 1

#5
#eeeee
#Sample Output 1

#5
#solution:-
def longest_palindromic_substring(s):
    n = len(s)
    dp = [[False for _ in range(n)] for _ in range(n)]
    max_len = 1
    start = 0
    
    # All substrings of length 1 are palindromes
    for i in range(n):
        dp[i][i] = True
    
    # Check for substrings of length 2
    for i in range(n-1):
        if s[i] == s[i+1]:
            dp[i][i+1] = True
            max_len = 2
            start = i
    
    # Check for substrings of length greater than 2
    for k in range(3, n+1):
        for i in range(n-k+1):
            j = i + k - 1
            if dp[i+1][j-1] and s[i] == s[j]:
                dp[i][j] = True
                if k > max_len:
                    max_len = k
                    start = i
                    
    return max_len
    
# Driver code
n = int(input())
s = input()
print(longest_palindromic_substring(s))
