from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB

emails = [
    "win a free iphone click here now",
    "urgent your bank account is suspended verify now",
    "congratulations you won 10000 rupees claim prize",
    "exclusive offer limited time get 50 percent off",
    "hey are you coming to class tomorrow",
    "can you send me the notes from today",
    "let me know once you reach the hostel",
    "meeting is rescheduled to 4 pm"
]

labels = [1, 1, 1, 1, 0, 0, 0, 0]

cv = CountVectorizer()
x = cv.fit_transform(emails)

model = MultinomialNB()
model.fit(x, labels)

msg = input("Enter email text: ")
data = cv.transform([msg])
res = model.predict(data)

if res[0] == 1:
    print("Spam")
else:
    print("Not Spam")
# 1 is for spam and 0 is for not spam 
