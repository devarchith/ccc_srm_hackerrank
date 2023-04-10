#Given a string s, find the length of the longest substring without repeating characters.

#Input Format
#
#The First line will have a integer N denoting the length of string.
#The Second line will have a string S.
#Constraints

#0 <= s.length <= 5 * 10^4
#s consists of English letters, digits, symbols and spaces.
#Output Format

#Print the integer which is the answer to the question

#Sample Input 0

#18
#fgsurhydrjkxjlvhvo
#Sample Output 0

#8
#Sample Input 1

#9
#mjjlclldn
#Sample Output 1

#3
#solution:-
def lengthOfLongestSubstring(s: str) -> int:
    n = len(s)
    ans = 0
    i = 0
    j = 0
    char_set = set()
    
    while i < n and j < n:
        if s[j] not in char_set:
            char_set.add(s[j])
            j += 1
            ans = max(ans, j - i)
        else:
            char_set.remove(s[i])
            i += 1
    
    return ans

# Taking input from user
n = int(input())
s = input().strip()

# Function call
print(lengthOfLongestSubstring(s))
