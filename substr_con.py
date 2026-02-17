from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        word_counts = Counter(words)
        res = []
        
        # We only need to check k possible starting offsets
        for i in range(word_len):
            left = i
            right = i
            curr_counts = Counter()
            count = 0 # Number of valid words in the current window
            
            while right + word_len <= len(s):
                word = s[right : right + word_len]
                right += word_len
                
                if word in word_counts:
                    curr_counts[word] += 1
                    count += 1
                    
                    # If we have too many of one word, shrink from the left
                    while curr_counts[word] > word_counts[word]:
                        left_word = s[left : left + word_len]
                        curr_counts[left_word] -= 1
                        count -= 1
                        left += word_len
                    
                    # If all words match exactly once
                    if count == num_words:
                        res.append(left)
                else:
                    # Word not in the list: reset window
                    curr_counts.clear()
                    count = 0
                    left = right
                    
        return res
