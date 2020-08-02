#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Human {
public:
  Human(string name, string type) : Name(move(name)), Type(move(type)) {}
  virtual void Walk(string destination) {
    cout << Type << ": " << Name << " walks to: " << destination << endl;
  }
  string getName() { return Name; }
  string getType() { return Type; }

protected:
  string Name;
  string Type;
};

class Student : public Human {
public:
  Student(string name, string favouriteSong)
      : Human(move(name), "Student"), favouriteSong(move(favouriteSong)) {}

  void Learn() const { cout << "Student: " << Name << " learns" << endl; }

  void Walk(string destination) override {
    cout << "Student: " << Name << " walks to: " << destination << endl;
    cout << "Student: " << Name << " sings a song: " << favouriteSong << endl;
  }

  void SingSong() const {
    cout << "Student: " << Name << " sings a song: " << favouriteSong << endl;
  }

public:
  string favouriteSong;
};

class Teacher : public Human {
public:
  Teacher(string name, string subject)
      : Human(move(name), "Teacher"), Subject(move(subject)) {}

  void Teach() const {
    cout << "Teacher: " << Name << " teaches: " << Subject << endl;
  }

public:
  string Subject;
};

class Policeman : public Human {
public:
  Policeman(string name) : Human(move(name), "Policeman") {}

  void Check(Human human) {
    cout << "Policeman: " << Name << " checks " << human.getType() << ". "
         << human.getType() << "'s name is: " << human.getName() << endl;
  }
};

void VisitPlaces(Human human, vector<string> places) {
  for (const auto& p : places) {
    human.Walk(p);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}
