from sklearn import metrics 
from sklearn.naive_bayes import GaussianNB 
from sklearn.model_selection import train_test_split 
from sklearn.datasets import load_iris 
iris = load_iris() 
X = iris.data 
y = iris.target  
trainX, textX, trainY, testY = train_test_split(X, y, test_size=0.6, random_state=3)
gnb = GaussianNB() 
gnb.fit(trainX, trainY) 
predictY = gnb.predict(textX) 
print("The Models accuracy is shown below: ") 
print(metrics.accuracy_score(testY, predictY)*100) 
print("\n\tLab by Utshav Paudel")