# Using Calculations

There are various options and settings available to calculate and display a final grade in the Gradebook.

## Calculations on the grade

All graded activities that are added to the online course will automatically be added
to the Gradebook. Students can have a range of assessments for which they will be
given a range of scores. The Moodle Gradebook:

- Stores the grades.
- Calculate a final grade based on a set of rules.

This implies a previous normalization process. Normalization means that when the grade given to an individual assessment, is converted into a decimal number for the calculation.

## Reasons to use normalization

Normalization is required in order to ensure that all the grades have the same base value so that they can be calculated fairly in relation to the maximum grade. To calculate a fair total, we need both of the grades to be recalculated to a decimal so that they have the same base value prior to adding them together for the final course grade. 

Calculation of normalization is the grade awarded, divided by the total grade possible so that all the graded activities have a base value of 10. 

The following table shows this for the two activities in this example:

|                     | Graded activity 1 | Graded activity 2 | Graded activity 3 |
| ------------------- | :---------------: | :---------------: | :---------------: |
| Maximum grade       |        25         |        100        |        50         |
| Grade awarded       |        10         |        30         |        10         |
| Grade normalization |        1.0        |       0.25        |        0.5        |

The normalization shows that the two awarded scores of 10 should not "weight" the same in the final course grade as they have significantly different decimal scores. This is this score that is used in the
aggregation process.

## Aggregation types

A wide range of aggregation types is available in Moodle. For the preceeding examples, the normalized grades of 1.0, 0.25, and 0.5 as shown in the previous example, will be used:

- The _mean of grades_ is the average score calculated as: (1.0 + 0.25 +0.5)/3=0.583.
- The _weighted mean of grades_ means that each item has a weight so the final grade is normalized. For example if first assessment has "x1" weight, the second "x2" and the thirt "x3", the final grade is calculated as: (1.0 + 0.25·2 + 0.5·3)/3 = 0.5.
- The _Simple weighted mean of grades_ is the default aggregation method (no settings changed). For example, one activity scores 100, other 50. The Gradebook first normalizes the grade and then multiplies that grade by the total grade possible.
- The _mean of grades (with extra credit)_ is kept to be compatible with older Moodle versions.
- The _median of grades_  uses mean insterad of average. 
- The _lowest grade_ reviews all the grades after normalization and presents the lowest score. 
- The _highest grade_ reviews all the grades after normalization and presents the highest score.
- The _mode of grades_ reviews and takes the most frequently is presented as
  the final grade, for example, 0.2, 1.0, and 1.0. The final grade is 1.0.
- _Sum of grades_ is the only aggregation method that does not use normalization. 

#### Maximum grades

It is possible to set a maximum score, then, Moodle calculate the final score based on it.

>  E.g. For example, 5 assessments each with a maximum grade of 250 sum 1250. However, the final grade might be 10. Therefore the aggregation convert the final score to 10 (not 1250).

##### Example

We have are three graded activities, each with a different maximum. 

The aggregation is set then as a calculation, the average of the grades. The maximum grade possible for
the whole course is 10.

| Assignment |        I |   II |  III | Total | Average | Final |
| ---------- | -------: | ---: | ---: | ----: | ------: | ----: |
| Max.       |      250 |  250 |  500 |  1000 |  333.33 |       |
| Score      |      150 |  120 |  300 |   570 |   190.0 |       |
| Normalized | 0.60[^a] | 0.48 | 0.60 |  0.57 |    0.57 |   5.7 |

[^a]: calculated as score/Máx for each assignment.
[^b]: calculated as average normalized (0.57) / number of assignmets (3)



The preceding table can be explained as follows:

- **(a)** : To calculate the normalized grade, the grade awarded is divided by the
  maximum grade for each assignment.
- **(b)** : The mean aggregation grade is calculated by adding together the
  normalized grade for each of the grade items. This is then divided by five
  (the total number of grades awarded).
- **(c)** : The final grade is 84 as the mean aggregation grade is multiplied by 100,
  which is the course maximum. If the course maximum was 30, the final grade
  would be *25.2 (0.84\*30=25.2)*.

Let's go into the Gradebook and set up some examples to see the aggregation types
in action and learn some other things that we can do to customize the Gradebook so
that it can further meet our needs.
