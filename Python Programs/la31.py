# Take any txt file and count word frequencies in a file.(hint : file handling + basics )

import string

def word_count(file):
    with open(file,'r') as file:
        wc={}
        words=file.read().split()
        for word in words:
            word=word.strip(string.punctuation)
            if word in wc:
                wc[word]+=1
            else:
                wc[word]=1
    return wc

file=input("Enter the file name: ")
print(word_count(file))