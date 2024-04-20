# Take any txt file and count word frequencies in a file.(hint : file handling + basics )

def count_word_frequencies(file_path):
    word_freq = {}
    with open(file_path, 'r') as file:
        # Read each line in the file
        for line in file:
            # Split the line into words
            words = line.split()
            # Count the frequency of each word
            for word in words:
                # Remove punctuation marks and convert to lowercase
                word = word.strip(",.?!-").lower()
                # Update word frequency dictionary
                if word:
                    word_freq[word] = word_freq.get(word, 0) + 1
    return word_freq

def print_word_frequencies(word_freq):
    for word, freq in word_freq.items():
        print(f"{word}: {freq}")

# Example usage:
file_path = input("Enter the path of the text file: ")
word_freq = count_word_frequencies(file_path)
print("Word frequencies in the file:")
print_word_frequencies(word_freq)
