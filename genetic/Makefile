JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $*.java

CLASSES = \
	Population.java \
	Individual.java \
	genTest.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class