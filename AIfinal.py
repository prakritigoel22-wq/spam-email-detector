import streamlit as st
import pandas as pd
import zipfile
import urllib.request
import io

from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.pipeline import Pipeline
from sklearn.metrics import accuracy_score

# Download dataset
url = "https://archive.ics.uci.edu/static/public/228/sms+spam+collection.zip"

with urllib.request.urlopen(url) as response:
    zip_file = zipfile.ZipFile(io.BytesIO(response.read()))

    data = zip_file.read("SMSSpamCollection")

# Read dataset
df = pd.read_csv(
    io.BytesIO(data),
    sep="\t",
    names=["label", "message"],
    encoding="utf-8"
)

# Separate messages and labels
X = df["message"]
y = df["label"]

# Split data into training and testing
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42, stratify=y
)

# Create machine learning model
model = Pipeline([
    ("vectorizer", CountVectorizer()),
    ("classifier", MultinomialNB())
])

# Train model
model.fit(X_train, y_train)

# Test model
predictions = model.predict(X_test)
accuracy = accuracy_score(y_test, predictions)

# Create application
st.title("Spam Email Detector")

st.write("Enter a message to check whether it is Spam or Not Spam.")

message = st.text_area("Enter your message here:")

if st.button("Check Message"):

    if message.strip() == "":
        st.warning("Please enter a message.")

    else:
        result = model.predict([message])[0]

        if result == "spam":
            st.error("This message is SPAM!")

        else:
            st.success("This message is NOT SPAM!")

st.write("Model Accuracy:", round(accuracy * 100, 2), "%")