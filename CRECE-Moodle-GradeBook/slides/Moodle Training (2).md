---
theme: gaia
size 16:9
paginate: true
header: CBHE-CRECE
footer: University of Vigo
_class: invert
color: #FFF
marp: true
backgroundColor: #000
---

# MOODLE Advanced Training <!-- Fit -->

---

# GRADE Aggregation topics

Weighted Mean, Simple Weighted Mean, and Natural

---

# Gradebook setup (i)

- Gradebook can be edited to suit your specific needs.
- Grades can be grouped into categories for ease of use.
– Grades can also be weighted.
- All grade settings are changed in Gradebook.

---



# Gradebook setup (ii)

- Once Gradebook is opened, selecting the “Setup” tab will allow instructors to manually add grade items, create and manage grade categories, manage category/item weights, and much more.

---

# Changing hanging the Gradebook

## Aggregation method

- For grade calculations, myCourses uses one of three aggregation methods.
- To change the aggregation method for your course’s gradebook, select the “Edit” drop-down shown on the same line as your course’s name.
- Then click “Edit settings.”
- Now you’re able to manage how the grades are calculated for the entire course.

---

#Aggregation options
- Select which grading method you would like to use.
- Also note that there is an option to drop the lowest grade(s).

---

# Weighted mean of grades

- This method of aggregation is best used with grade categories.
- With it, you can assign each category to be worth a certain percentage of the overall course’s grade.
- For example:
  - In my EQI2 2021 course, the project that students do is worth 30% of their grade.
  - Exams make up the remaining 80%.

---
WEIGHTED MEAN OF GRADES

• As an example, let’s consider the following grade set:

**Homework Assignments (30%)**

**Exams (70%)**

Student

Score

Total

Possible

Student

Score

Total

Possible

HW 1

HW 2

HW 3

HW 4

18

31

10

5

20

35

15

25

E 1

E 2

E 3

88

55

100

100

100

**300**

76

**TOTA**

**L**

**219**

**TOTA**

**L**

**64**

**95**

• For t

ow the homework to be weighted at

30% and the exams at 70%.





WEIGHTED MEAN OF GRADES

• Moodle multiplies the category total by the weight.

– If there are no categories, Moodle will multiply the weight by the

individual grade total.

• So, for our example…

**Homework Assignments (30%)**

**Exams (70%)**

Student

Score

Total

Possible

Student

Score

Total

Possible

Total

64

95

Total

219

300

**Exam**

**Grade**

**HW Grade**

**20.21**

**51.10**





WEIGHTED MEAN OF GRADES





SIMPLE WEIGHTED MEAN OF

GRADES

• For the Simple Weighted Mean of Grades, Moodle uses the

total possible points as the weight of an assignment (or

category).

• So, let’s consider th

**Student Grades**

Student

Total

Score

Possible

HW

1

18

20

HW

2

31

10

5

35

15

25

HW

3

HW

4





SIMPLE WEIGHTED MEAN OF

GRADES

• Each grade is calculated individually (if no categories are

employed).

– That ratio (score/total) is then multiplied by the total possible points.

**Student Grades (Partial Table)**

Student

Score

Total

Possible

Ratio Weight

HW

1

18

18

31

10

5

20

35

15

25

20

35

15

25

20

31

35

10

15

5

HW

2

HW

3

HW

4

25





SIMPLE WEIGHTED MEAN OF

GRADES

**Student Grades (Full Table)**

Student

Score

Total

Possible

Ratio Weight Calculatio

Total

n

HW

1

18

20

31

35

10

15

5

18

20

31

35

10

15

5

18

31

10

5

20

35

20

35

18

31

10

5

⋅ 20

HW

2

⋅ 35

HW

3

15

15

⋅ 15

HW

4

25

25

⋅ 25

25

88

25

88

E 1

E 2

E 3

88

55

76

100

100

100

100

100

100

88

55

76

⋅ 100

⋅ 100

⋅ 100

100

55

100

55

100

76

100

76

100

100





SIMPLE WEIGHTED MEAN OF

GRADES

• Once the weights are applied to each grade, they are summed.

– That sum is divided by the sum of the weights.

**Student Grades**

Total Weight

HW 1

HW 2

HW 3

HW 4

E 1

18

31

10

5

20

35

15

25

88

55

76

100

100

100

E 2

E 3

**TOTA**

**L**

**283**

**395**





NATURAL

• If you didn’t catch it in the previous slides, the simple weighted

mean of grades will return the exact same grade as the natural

aggregation.

– The student scores are added to a single total.

– The total possible points are added to a single total.

– To get the grade, simply divide the student score total by the sum of

the total possible points.





NATURAL

**Student Grades**

Student

Total

Score

Possible

HW 1

HW 2

HW 3

HW 4

E 1

18

20

31

35

10

15

5

25

88

100

100

100

E 2

55

E 3

76

**TOTA**

**L**

**283**

**395**




