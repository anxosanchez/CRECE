# Grading examples

## Case practice 1: mean of grades

The parameters of this example are related on table 1.

| Assignment | Max. grade |
| ---------- | ---------- |
| Task 1     | 100        |
| Task 2     | 100        |
| Task 3     | 50         |

Grade tasks 1 and 2 for at least one learner. Steps are:

| Step | Action                                                       |
| ---- | ------------------------------------------------------------ |
| 1.   | Go to _Grades_ and choose the _aggregation type__            |
| 2.   | Click on _Administration_ and then on _Grades_. The overall averageshow an average grade based on all the students rather than an individual student's averagegrade (it is shown for all aggregation types). |
| 3.   | From drop-down list find _Categories and items_, choose _Simple view_. |
| 4.   | Customize the Gradebook and choose the aggregation type. Go to _Categories and items_ change the aggregation to _Mean of grades_, then click on _Save changes_ (not the only way to this). |
| 5.   | Max grade_ shows the maximum grade possible for each graded item. The number at the bottom of the table is the total final grade possible. In this example, 100. |
| 6.   | In the drop-down list find _View_  and click on _Grader report_. |

We can customize choosing the _arrgegation type_. Inthis case wur choose _Mean of grades_.

Take a look at the information of _User 3_ who has completed two assessments that have been graded. His current course total is 95.50 (91+100)/2. However, this only works because the course total is the same as the assignment maximum grades. 

| User           | Task 1 | Task 2 | Task 3 | $\overline{x}$ course total |
| -------------- | -----: | -----: | -----: | --------------------------: |
| User 1         |   94.0 |        |        |                        94.0 |
| User 2         |   99.0 |        |        |                        99.0 |
| User 3         |   91.0 |  100.0 |        |                        95.5 |
| User 4         |   86.0 |  100.0 |        |                        93.0 |
| User 5         |   70.0 |   80.0 |        |                        75.0 |
| Overal average |   88.0 |   93.3 |        |                        91.3 |

If the course total was 75, we could not have performed this simple calculation for the course total. This is why Moodle first normalizes grades and then multiplies this by the maximum course total possible. 

So, the calculation that Moodle is actually doing for _User 3_ is:

|                  |     Task 1 |  Task 2 |    Total | Mean      |    Final |
| ---------------- | ---------: | ------: | -------: | --------- | -------: |
| Max grade        |        100 |     100 |          |           |          |
| Grade actual     |       91.0 |   100.0 |    191.0 | 95.50     |          |
| Normalized grade | 0.91([^a]) | 1.0[^b] | 1.91[^c] | 0.995[^d] | 95.5[^e] |

[^a]: 91/100
[^b]: 100/100
[^c]: (0.91+1.0)
[^d]: 1.91/2
[^e]: (95.5*100)

This score means that all assignments have been completed.

### Including all graded activities

We can tell the Gradebook to include all the graded activities in the aggregation.
Moodle will add up each assessed activity, which will include a zero score for each
assessed item that has not been submitted or graded yet, and then it will divide the
grade by the total number of assessed grades in the course regardless of whether
they have been graded or not. 

In this example, it will be divided by three. Let's go and apply this and see it in action:

| Step | Action                                                       |
| ---- | ------------------------------------------------------------ |
| 1.   | Go to _Categories and items_, on _Simple view_.              |
| 2.   | In _Actions_ first icon click on that icon (is an edit icon) . |

Let's take a look at the Gradebook again to see what difference this has made (__View_, click on _Grader report_).

The calculation that is taking place for _User 3_ as follows:

| Name            | Task 1 | Task 2 | Task 3 | Course total |
| --------------- | -----: | -----: | -----: | -----------: |
| User 1          |  94.00 |      - |      - |        31.33 |
| User 2          |  99.00 |      - |      - |         33.0 |
| User 3          |  91.00 | 100.00 |      - |        63.67 |
| User 4          |  86.00 | 100.00 |      - |        62.00 |
| User 5          |  75.00 |  80.00 |      - |        51.67 |
| Overall average |   88.0 |  93.33 |      - |        48,33 |



|                  |     Task 1 |  Task 2 | Task 3 |    Total | Mean       |    Final |
| ---------------- | ---------: | ------: | -----: | -------: | ---------- | -------: |
| Max grade        |        100 |     100 |     50 |          |            |          |
| Grade actual     |       91.0 |   100.0 |      0 |    191.0 | 63.67      |          |
| Normalized grade | 0.91([^f]) | 1.0[^g] |  0[^h] | 1.91[^h] | 0.6367[^i] | 95.4[^e] |

[^f]: 91/100
[^g]: 100/100
[^h]: 0/50
[^i]: 0.91+ 1 + 0
[^j]: 1.91/3
[^k]: 0.06367*100

### The simple weighted mean of grades

Let's change the aggregation of the course and see what it does to the final grade:

| Step | Action                                                       |
| ---- | ------------------------------------------------------------ |
| 1.   | Go to _Categories and items_ again and clicking on _Simple view_. |
| 2.   | Change the aggregation type to _Simple weighted mean of grades_ in the _Aggregation_** column and click _Save changes_. |
| 3..  | Switch back to view the Gradebook. _View_ and click on _Grader report_. |

The calculation used in the simple weighted mean of grades is shown in the following table:

|                  | Task 1 | Task 2 | Task 3 |  Total |   Mean | Final |
| ---------------- | -----: | -----: | -----: | -----: | -----: | ----: |
| Max grade        |    100 |    100 |     50 |        |        |       |
| Grade awarded    |  91.00 | 100.00 |   0.00 | 191.00 |  63.67 |       |
| Normalized grade |   0.91 |   1.00 |   0.00 |   1.91 | 0.6367 | 63.67 |

In this aggregation method, this normalized grade is multiplied by the maximum grade possible for
the assessed activity.

Instead of dividing the normalized total by the number of grades in the course (in our example, this meant dividing the total by three), the simple weighted mean aggregation divides the normalized total by the total maximum grade possible (which is each of the maximum grades for each activity added together). 

### The weighted mean of grades

Each graded item is manually given a weighting. In the mean of grades method, there is no weighting involved as it is a simple average calculation. 

Making use of the weighting option within the weighted mean of grades:

| Step | Action                                                       |
| ---- | ------------------------------------------------------------ |
| 1.   | Go to _Categories and items_.                                |
| 2.   | Change _Aggregation_ type to _Weighted mean of grades_. Appears a new column in _Categories and items_. This is the _Weight_ to apply to each graded item. Default is 1.0. |
| 3.   | Switch back to view the Gradebook. find _View_ and click on _Grader report_. |

This affects the grade this way:

|                  | Task 1 | Task 2 | Task 3 |  Total |     Mean | Final |
| ---------------- | -----: | -----: | -----: | -----: | -------: | ----: |
| Max grade        |    100 |    100 |     50 |        |          |       |
| Grade awarded    |  91.00 | 100.00 |   0.00 | 191.00 |    63.67 |       |
| Weighting        |      1 |      2 |      1 |        | Total: 4 |       |
| Normalized grade |   0.91 |   2.00 |   0.00 |   2.91 |   0.7275 | 72.75 |