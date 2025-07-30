# TODO

print('Text: ')

text = str(input())

lettercount = 0
wordcount = 0
sentencecount = 0

for i in range(len(text)):
    if (65 <= ord(text[i]) <= 90) or (97 <= ord(text[i]) <= 122):
        lettercount += 1
    elif ord(text[i]) == 32:
        wordcount += 1
    elif ord(text[i]) in [33, 63, 46]:
        sentencecount += 1
    else:
        continue

wordcount += 1
L = lettercount / wordcount * 100
S = sentencecount / wordcount * 100
index = 0.0588 * L - 0.296 * S - 15.8

if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")