# Grading examples

## Mean of grades

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

In the mean of the grades aggregation type the totals for each assignment type are not considered in the final aggregation. However, the maximum grade of each assignment is very important. This aggregation type uses the assignment totals in the mean aggregation step of the calculation.

| Step | Action                                                       |
| ---- | ------------------------------------------------------------ |
| 1.   | Go to _Categories and items_ for any of the possible ways).  |
| 2.   | Change the aggregation type to _Simple weighted mean of grades_ in _Aggregation_, and _Save changes_. |
| 3.   | Switch back to the Gradebook. Find _View_ and click on _Grader report_. |

Note how the course total score has changed. Look at **Bayley W** again. His previous
score in the mean of grades aggregation was **63.67** (remember that the Gradebook is
currently using all the assessed activities in the calculations and not just those that
have been marked and graded). His score is **76.40** now.

The calculation used in the simple weighted mean of grades is shown in the
following table:



|                        | Task 1 | Task 2 | Task 3 | Total |   Mean | Final grade |
| ---------------------- | -----: | -----: | -----: | ----: | -----: | ----------: |
| Maximum grade possible |  100.0 |    100 |     50 |       |        |             |
| Grade awarded          |     91 |    100 |      0 | 191.0 |  63.67 |             |
| Normalized grade       |   0.91 |      1 |      0 |  1.91 | 0.6367 |       63.67 |

shown in the
Gradebook

100 100 50 250

91.00 100.00 0 191 63.67
Normalized
grade
0.91
(91/100)
1
(100/100)
0
(0/50)
1.91
(.91+1+0)
Plus
weighting
91
(.91*100)
100
(1*100)
0
(0*50)
191
(91+100+0)
.764
(191/250)
76.40
(.764*100)

```

```

As done previously, the grade awarded is normalized. However, in this aggregation
method, this normalized grade is multiplied by the maximum grade possible for
the assessed activity. (In theory, the normalization process is not required in this
aggregation type, as the normalization and weighting calculations cancel each other
back to the original grade awarded. However, in practice, Moodle always normalizes
this aggregation type.) However, the calculation of the mean aggregation is different
in this method.

Instead of dividing the normalized total by the number of grades in the course
(in our example, this meant dividing the total by three), the simple weighted mean
aggregation divides the normalized total by the total maximum grade possible
(which is each of the maximum grades for each activity added together). In this
case, it divides the normalized and weighted total by 250.

There is one final method of calculating a mean grade and this requires some
additional options to be set by the teacher. Let's have a go at using the 'weighted
mean of grades' aggregation method.

#### The weighted mean of grades

In this method, each graded item in the course is manually given a weighting. In
the mean of grades method, there is no weighting involved as it is a simple average
calculation. In the simple weighted mean of grades, the weighting is based on the
maximum grade possible for each graded item. In a weighted mean, the teacher sets
the weighting within the Gradebook. An example use of this aggregation type is
when a specific assignment is worth more to the final course grade than others. For
example, in our sample activities, **Task 1** and **Task 2** both have a maximum grade of

1. However, **Task 2** might require a lot more detail and research to complete the
   task and therefore, it should contribute more to the final grade than **Task 1**. With
   the simple weighted mean aggregation type, the two tasks will be treated equally.
   However, we can reflect the additional work within the final grade by making use
   of the weighting option within the weighted mean of grades:
2. Go to **Categories and items** again.
3. Change the **Aggregation** type to **Weighted mean of grades**.
   There are further changes that now need to be made here. Once the weighted
   mean of grades has been chosen, a new column appears on the **Categories**
   **and items** page. This is the **Weight** column and it allows us to apply a
   weight to each graded item. The default for each item is **1.0**. However, in this
   example, **Task 2** has been changed to a weighting of two in order to reflect
   the additional work required when completing this activity.

```
You can also use the weighted mean of grades to exclude a grade
from the course total. To do this, we will need to change the
weighting to 0.0.
```

*Using Calculations*

1. Change the weighting of **Task 2** to **2.0** and click on **Save changes** at the
   bottom of the screen.

Let's see how this affects the final grade:

- Switch back to view the Gradebook. In the drop-down list at the top of the
  screen, find **View** and click on **Grader report** (or click on **view** in the tab at
  the top of the Gradebook screen).

```
Chapter 5
```

The course totals have changed again, so let's see how this is calculated. In this
method of calculating a mean grade, each normalized grade is multiplied by the
weight applied to the assessed item. The normalized grades are added together and
then divided by the total weights applied to the course. The following table shows
you the calculations for this aggregation method for the grades of **Bayley W** :

```
Task 1 Task 2 Task 3 Total Mean
aggregation
Final grade
shown
in the
Gradebook
Maximum
grade possible
100 100 50
Grade awarded 91.00 100.00 0 191 63.67
Weighting 1 2 1 Total: 4
Normalized
grade
0.91
(91/100*1)
2
(100/100*2)
0
(0/50*1)
2.91
(0.91+2+0)
0.7275
(1.91/4)
72.75
(.7275*100)
```

Note that **Task 2** is multiplied by two as this is the weighting we applied for this
assessed activity. The mean aggregation is calculated by dividing the total weighted
normalized score by four, as this is the total number of weights applied to the
course (that is, a weighting of one for **Task 1** , a weighting of two for **Task 2** ,
and a weighting of one for **Task 3** ).

We have seen three ways of how to calculate a mean grade within a course and
customize the Gradebook by choosing to include all assessed activities within the
Gradebook rather than just the graded activities. Another popular aggregation
method is the sum of grades, which acts differently to the normalized methods
already discussed. Let's have a go with this aggregation method. We will also
look at some other customizations available in order to change how the grade
is displayed within the Gradebook.

*Using Calculations*

### Example two – The sum of grades

In this example, we will look at the 'sum of grades' aggregation type. The course has
five assignments for the students to complete, each with a different final grade.

With the following screenshot, you can see how this example course has been set up:

Note the maximum grades for each assessed activity. The maximum grade
for the course is the total of each assessed item within the course.

To change the aggregation type, you will use the same process as the one
used previously:

1. Go to **Categories and items**.
2. Change the aggregation type to **Sum of grades** and click on **Save changes**
   at the bottom of the screen.
3. Now, switch back to **View** ( **Grader report** in the drop-down list) in the
   Gradebook.

```
Chapter 5
```

The calculation for this aggregation is simple. Each graded item is added together
and presented as the course total grade. Normalization does not occur, and it is not
possible to exclude empty grades (ungraded items). This aggregation simply adds
each item to the total as it is graded.

However, it is possible to apply some extra credit within this grade type.

Go back to the **Categories and items** page from within the grades area and notice the
**Extra credit** column. For each graded item within the course, there is an option for it
to be chosen for extra credit. So, what does this do?

Any item that has extra credit applied to it is considered an additional assessment
and therefore, the maximum grade is not used in the course total.

For example, the course can have four required tasks. A student might not submit
**Task 2** on time or not get a sufficient grade, but they are not allowed to resubmit.
**Task 5** could be an additional or alternative task that can be used to increase the final
course score. Another use of extra credit could be where the student has completed all
work but has the option to improve their final grade by completing additional work.

*Using Calculations*

In the example we are using, the course total is currently 360, which is calculated
by adding all the maximum grades of each assessed item together. We are going to
set **Task 5** as the extra credit. This will mean that the maximum grade of 80 is not
included in the calculation of the course total. Let's apply this; go to the **Categories
and items** screen and check the Extra credit column for **Task 5** and click on **Save
changes** at the bottom of the screen.

Note that the course total grade is now 280 instead of 360.

The maximum grade that a student can receive will always be 280. For example, if
a student receives a grade of 100 in **Task 1** , 50 in **Task 2** , 30 in **Task 3** , 100 in **Task
4** , and also completes **Task 5** and receives a grade of 80, their course total will still
say 280. This is because it is not possible to get a grade that is higher than the course
maximum. However, the extra credit will mean that students have an additional
chance to receive the highest grade possible.

```
Chapter 5
```

#### Viewing letter grades in the Gradebook

Until now, we have been viewing the results in the Gradebook as numbers.

In *Chapter 2* , *Customizing Grades* , we created letter grades to show numbers as a
corresponding word of our choice rather than the numbers that we used to grade
(for example, **Distinction** instead of **100** ). We used the following percentages for
the grade letters:

```
Letter grade Highest percentage Lowest percentage
Distinction 100% 100%
Merit 99.99% 75%
Pass 74.99% 50%
Not yet complete 49.99% 0%
```

If you are following these instructions within your own course, then make sure that
you have the letter grades set up, as shown in the preceding table. If you cannot
remember how to do this, refer to *Chapter 2* , *Customizing Grades*.

We can apply these to our Gradebook so that instead of seeing a final number grade,
we will see a word based on the percentage that the learner has received.

This takes some setting up! Take a look:

1. Go to the **Grades** area (navigate to **Administration** | **Grades** )
2. Go to **Categories and items** (either by clicking on the drop-down list and
   clicking on **Simple view** under the **categories and items** heading, or by
   clicking on **Categories and items** on the tabs bar).
3. Click on the edit icon at the top of the **Actions** column (this is usually a cog
   icon, and it will be next to the category aggregation drop-down list).
4. You need to view the **Category total** options and click on **Show more** to see
   the settings we need.
5. Look for the **Grade display type** option. It probably says **Default (Real)** in
   the current setting. Click on the drop-down list and you will see a range of
   options. There are three main options:
   ° **Letter** : This shows you the relevant letter grade in relation to the
   percentage setup in the letter grades options.
   ° **Percentage** : This will show you the grade as a percentage. Moodle
   will calculate the percentage grade based on the grade awarded and
   the maximum grade possible.
   ° **Real** : This will show you the actual grade awarded in the grading
   process. This is what is currently displayed as the default.

*Using Calculations*

```
You might notice that there are actually more than three options available in
the drop-down list. You will see that more options are there apart from the
ones described in the preceding points. This allows you to choose two grades
to be shown within the Gradebook. For example, if Letter (percentage) is
chosen, the letter will be shown as the main grade in the Gradebook, and
the corresponding percentage will be shown in brackets next to it.
```

1. From the drop-down list, choose **Letter** and click on **Save changes** at the
   bottom of the screen.
2. Switch back to **View** ( **Grader report** in the drop-down list) in the Gradebook.

Take a look at the course total and note that the **Course total** column now has
the words that have been set up as the letter grades. These are shown based on a
calculated percentage grade, which is based on the work graded so far.

```
Chapter 5
```

You can see that **Ava B** and **Bayley W** have not yet received sufficient grades
to gain an actual grade yet (which means that they have received less than a 50
percent grade according to how our letter grades have been set up). As more work
is completed and graded, the course total will increase and therefore the final grade
will change.

Note that the tasks are still displayed as real number grades. It is possible to change
the settings for individual assignments in order to display alternative grade display
types as well. Let's go in and change these:

1. Go back to **Categories and items**.
2. This time, click on the edit (cog) icon next to the first graded item on the list
   (in the example we have been using, this will be **Task 1** ).
3. Find the **Grade display type** option (you will need to click on **Show more** )
   and change it to **Letter**.
4. Click on **Save changes** at the bottom of the screen.

Repeat this process for all the assessed activities in the course (or as many as you
want in order to show a letter grade instead of a number grade). Take a look at
the grader report again to see the letter grades instead of numbers shown in
the Gradebook.

The process to change the way in which the grades are displayed is the same for
all types of aggregation and any graded activity. However, it always needs to be
completed through the Gradebook for each individual item, so it could be quite
time-consuming for courses with lots of graded items.

If the course is going to use the same grade display types, you can set the course
default to an alternative (other than **Real** , which is the current default).

*Using Calculations*

##### Setting the course default for the grade display type

The course default can be set up as follows:

1. Within the **Grades** screen, we need to go to the **Settings** area (if using the
   drop-down list, find the **Settings** heading and click on **Course** ; if using the
   tabs view, click on **Settings** ).
2. Find the **Grade item settings** section and click on the drop-down list to
   change the **Default (Real)** option to the option you would like for the course.
   Save the changes on this screen.

You will still be able to change each assignment type or total to an alternative grade
display type, but all future graded activities will be presented as this chosen grade
display type within the course.

### Example three – using scales

So far, we have been using the Gradebook with number grades (apart from choosing
to view these as letter grades). However, courses can also use scales, which are often
words used for grading instead of numbers. In *Chapter 2* , *Customizing Grades* we set
up a word scale for **Not yet complete** , **Pass** , **Merit** , and **Distinction**. When marking
as assignment, we pick one of these words as the grade.

Remember that scales have a simple scoring system based on the number of items
in the scale rather than true numbers. Therefore, they are not always the best option
for complex calculations. However, let's use some scales in the Gradebook to see the
calculations in action.

For this example, there are five tasks within the course, and each one is graded
on the **PMD** scale set up in *Chapter 2* , *Customizing Grades* (with these options for
grading: **Not yet complete** , **Pass** , **Merit** , and **Distinction** ).

```
Chapter 5
```

You can see how these have been graded so far in the following screenshot:

The course aggregation for this example has been set to **Sum of grades** , and
the Gradebook adds together each grade that is awarded in order to show the
course total.

Remember, from *Chapter 2* , *Customizing Grades* , the numbers that are used in
calculations when using scales are based on the number of items in the scale.
In this four-point scale, the grades will be 1 to 4 ( **Not yet complete** = **1** , **Pass** = **2** ,
**Merit** = **3** , and **Distinction** = **4** ) as the sum of grades is not a normalized scale.

Take a look at **Emilie H** in the previous screenshot. Her course total is 10. This is
calculated in the following way:

*3 (Merit) + 4 (Distinction) +3 (Merit) = 10.*

Let's change the aggregation type from **Sum of grades** to **Mean of grades** in the
**Categories and items** screen. Also, make sure that the course total at the bottom
of the screen says **100.00**. If it does not, then change the number and click on **Save
changes** at the bottom of the screen. Go back to the **Grader** view to see how the
course total has changed.

*Using Calculations*

Take a look at **Emilie H** again. This aggregation method uses a normalization
process, and the calculation is shown in the following table. As we know, the scores
used with scales will always be based on the number of items in the scale and the
Gradebook will always use either 0 or 1 (depending on the aggregation chosen) for
the first item in the scale. When using normalized aggregation, methods scales start
from 0, so the four-point scale will have a range from 0 to 3 ( **0** = **Not yet complete** ,
**1** = **Pass** , **2** = **Merit** , and **3** = **Distinction** ).

```
Task 1 Task 2 Task 3 Total Mean
aggregation
The final
grade shown
in the
Gradebook
Maximum
grade
possible
3 (for
distinction)
3 3
Grade
awarded
2 (merit) 3 (distinction) 2 (merit) 7 2.333
Normalized
grade
0.6667
(2/3)
1
(3/3)
0.6667
(2/3)
2.3334
(0.6667 + 1
+ 0.6667)
0.7778
(2.3334/3)
77.78
(0.7778*100)
```

This process will be the same for all normalized methods (with the aggregation
calculation relevant to the method chosen).

In these two examples, the course total has been shown as numbers. However, it is
possible to set the course total to use the scale as well.

1. Go to the **Categories and items** area in the Gradebook and click on the edit
   button next to the **Aggregation** drop-down menu.
2. In the **Category total** section, find the **Grade type option** and choose the
   scale from the list.
3. This will activate the **Scale** drop-down list. From this list, choose the **PMD**
   scale, which is the same scale used for the individual assessments.
4. Click on the **Show more** text to view the **Grade display type** options.

```
Chapter 5
```

1. Make sure that the **Grade display type** option says **Real** and **Save changes** at
   the bottom of the screen.
2. Now, switch back to **View** the **Grader report** option again.

You can see that the course total is now using the same scale as the graded items.

The **Course total** scale uses the same scoring as the individual items and uses the
aggregation method to decide which item of the scale is to be displayed.

*Using Calculations*

Take a look at **Emilie H** again. Remember that the normalized total was **2.3334**. As
two equates to **Merit** in this four-point scale, **Merit** is shown as the course grade.
Remember, this example does not use the nongraded assessments in the total, so
the grade will change as other assignments are completed. If the normalized grade
is calculated as. **5** , the final grade will be rounded up. For example, the normalized
grade of **Bayley W** will be **2.5** (a grade of **2** for **Merit** and a grade of **3** for **Distinction**
to make a total of **5** .) This, divided by two for the number of grades in the mean
calculation, provides the **2.5** normalized total. This is rounded up to display a final
course grade of **Distinction**.

### Example four – using outcomes

We have seen a range of ways in which Moodle can use numbers, letters, and words
to calculate the final course total. We will now look at how the outcomes we set in
*Chapter 2* , *Customizing Grades* can be used in the course totals.

In this example, two assignment tasks have been set up with no grade but each has
different outcomes applied to them. The outcomes are graded using the completion
scale set up in *Chapter 2* , *Customizing Grades*.

When marking this work, only the outcomes are graded (as either **Not yet complete** ,
**Partially complete** , or **Complete** ). We will need to tell the Gradebook to include
outcomes in the grade aggregation.

For this example, students need to ensure that all the assignment outcomes are
complete so a lowest grade aggregation will be used. This is useful as all outcomes
need to be marked as complete for the course to be complete. If there is one **Not yet
complete** or **Partially complete** grade, this will be shown as the course total and
therefore, teachers and students will know that some work still needs to be completed.
Once all outcomes are graded as complete, the lowest grade will be **Complete** and
this will be shown in the **Course total** column. For these elements to be shown in the
course total, the **Course total grade type** option needs to be the 'complete' scale. This
process requires a running total based on all the required elements, so the aggregation
must include nongraded (empty) items in the Gradebook.

There is one new element that needs to be applied here, in addition to settings
we have previously used. In the following instructions, only the new step (that is,
choosing to include the outcomes in the grade aggregation) will be explained. The
other steps will be stated but you will need to use previously learned knowledge (or
look back through previous pages) to apply them:

1. Go to the **Categories and items** screen.
2. Change the **Aggregation** type to **Lowest grade**.

```
Chapter 5
```

1. Click on the edit icon in the **Actions** column, then click on **Show more** in the
   **Grade category** section, and remove the tick in the box next to **Aggregate**
   **only non-empty items**. Also, click on the box to add a tick next to **Include**
   **outcomes in aggregation**.
2. In the **Category total** section, ensure that the **Grade type** option is set to
   **Scale** and choose the **Completion** scale from the drop-down list.
3. Make sure the **Grade display type** option is set to **Real** (we need to click
   on **Show more** to check this).
4. Scroll to the bottom of the screen and click on **Save changes**.
5. Then, switch to **View** the full **Grader report**.

When using outcomes, the Gradebook screen has a lot more information in it as
each outcome is listed as an additional column on the screen. Using lots of outcomes
can make the Gradebook a little difficult to use and will require some scrolling on
your screen. However, you can see some of the items that have been graded and the
course totals in the following screenshot:

No grade will be shown in the main assignment column ( **Task 2** in the previous
example) as it has been set up with no grade, but it has two outcomes (shown with a
circle icon) attached to it, which are are graded with a scale. While work is still being
submitted and graded, the course total will remain **Not yet complete**. Once a grade
has been awarded to all outcomes, the lowest grade will be the one that is shown
as the **course total** option. **Emilie H** has submitted all her work and it has been
graded, but there is still at least one element that is only partially completed, which
is reflected in her course total. However, we can see that **Madeline W** has completed
all her tasks, so her course total shows as **Complete**.

*Using Calculations*

### Summary

In this chapter, we saw a range of ways in which the Gradebook can be used to
display student grades and calculate final course grades. We saw how numerical
grades and scales can be calculated to show a final course grade. We also
investigated how the different grading types and aggregation methods can be used.

With many options available within the Gradebook, aggregation types can be
quite confusing. However, having worked through the examples, you should
now have a better understanding of the key settings related to the calculation of
grades within the Gradebook. This should give you an overall understanding of the
aggregation types and settings available, and you can also refer to the chapter in
the future to apply the settings you need for your course. You can find explanations
of each of the category types at Moodle.org: https://docs.moodle.org/27/en/
Category_aggregation

In *Chapter 6* , *Organizing the Gradebook Using Categories* , we will see how we can further
customize the Gradebook to organize grades into categories.

# Organizing the Gradebook

# Using Categories

The Gradebook can be difficult to use due to the amount of information shown
within the table, especially in a course that uses a lot of graded activities. Often,
the main course screen is arranged by topics in order to organize the content, and
we can apply a similar process to the Gradebook through the use of categories to
group grades by topic, assessment type, or any other preferred arrangement.

We have seen how we can carry out course calculations based on how we want
all the assignments to be added together. However, what if you want one set of
assessments to be calculated as a mean of grades and another group of tasks to
show the highest grade? What if you don't want some of the grades to be used
in the calculations? We can use categories in a range of ways in order to group
assessments together, such as by topic or assessment type. We can also use
categories to enable some assessments to have a higher weighting than others.
In this chapter, we will:

- Create categories and learn how to add graded activities to them
- See how categories can provide a range of aggregation types within
  one course
- See ways in which we can exclude grades from the final course total

*Organizing the Gradebook Using Categories*

### Adding categories

Categories enable you to group graded activities within the Gradebook so that they
can be viewed together and provide additional options to calculate final course
grades. We will look at how they can be used throughout this chapter but first, we
need to add some categories. We need to create the categories using the **Grades** area
of the course:

- Go to the **Grades** area and then go to the **Categories and items** screen
  (if using the drop-down list, you will need to choose **Simple view** ).
- At the bottom of the **Categories and items** screen, there is a button that
  says **Add category**. Click on this and a new screen will appear.
- Give the category a name (such as Unit 1). Note that the options you
  get when setting up the category are the same as the options we used in
  *Chapter 5, Using Calculations* to set up how the course should be aggregated.
  This includes the grade display type as well as the aggregation method.
  You can choose the same type of aggregation as the course or use one
  specific aggregation type for this unit.
- In the **Category total** section, you can set a **Maximum grade** option for the
  category. Category totals will work in exactly the same way as the course
  total in order to set a maximum grade available. For example, if Unit 1 has
  three assessments each worth 100 but the maximum for Unit 1 is 100, the
  maximum grade can be set and the aggregation will take this into account
  when presenting a final category total. See the upcoming information box
  for how this affects the course totals.
- Make any further changes you would like to make to the category.
- When you have added at least one category, you get an additional option
  at the bottom of the screen in order to choose a **Parent category** option. This
  allows you to choose whether the category will be a main or a subcategory
  (a subcategory is a category nested within another category). We will look
  at the use of subcategories later in the chapter.
- Scroll to the bottom of the screen and click on **Save changes**.

```
When using categories, the course total is calculated using the
category totals instead of the individual assessment grades.
The category will complete the selected aggregation when it
is created and present a category total. The course total will
then use each category total in the aggregation that has been
selected for the course total.
Chapter 6
```

If graded activities have already been added to the course, you can use the **Categories
and items** screen to move graded activities to the relevant categories. Once categories
have been set up, you can choose the relevant category when initially adding the
graded activity to the course.

To move the graded activities into categories, check the small **Select** box next to each
activity that you want to move (the **Select** column is on the right-hand side of the
screen) and at the bottom of the screen, click on **Move selected items to** and choose
the category you would like them to be moved to. You can also use the standard
move icon in the **Actions** column to move individual items as required, as shown:

You can also move the order of the categories after they have been created using the
moving icon:

1. Click on the move icon next the category you want to move (in the **Actions**
   column). This will temporarily remove the category from the screen.
2. White boxes will appear on the screen in all the places where can move the
   category to.
3. Click on the space where you would like the category to be.

*Organizing the Gradebook Using Categories*

In the following screenshot, you can see that there are three categories within the
course and there are two aggregation types used in the course:

For this example, the total of **Unit 1** will be calculated using the 'mean of grades'
aggregation type, which means that the graded items will be divided by 2 (the total
number of graded items in the category).

**Unit 2** will present the sum of grades (in this case, the total of one assignment) as the
category total.

**Unit 3** will also show a sum of grades of the two assignments as the category total.

The course total will be **Sum of grades** (as shown at the top of the preceding
screenshot), which will add together all the grades awarded and shown in the unit
category totals. This calculation will be *Unit 1 + Unit 2 + Unit 3*. Individual assessment
grades will only be included in the final grade if they are not in a category.

```
Chapter 6
```

### Excluding assessments from the final grade

There might be elements of the online course that are assessed but do not count
toward a final grade. These could be formative assessments such as homework
activities, quizzes to enable self-assessment, and so on. These graded items will
automatically appear in the Gradebook, but you might not want the grades to be
counted in the final category or the course total.

There are two main ways in which we can do this. One is to exclude a graded
activity for all students and the other is to exclude individual grades for each
individual student.

#### Excluding assessments from the aggregation for all students

There are a few ways in which this can be achieved. One has already been mentioned
in *Chapter 5* , *Using Calculations* , when using the weighted mean of grades. There are
two further ways in which this can be achieved, and both require the use of categories.

If you would like all the graded items that do not count for the course total to be in
one category, you can do the following:

1. Go to the **Grades** area and then go to the **Categories and items** page
   (if using the drop-down list, choose **Simple view** under the **Categories**
   **and items** heading).
2. Scroll to the bottom of the screen and click on **Add category**.
3. Give the category a name (such as formative assessments or not used
   for final grade).
4. Make sure the aggregation is not a sum of grades (any other aggregation
   method is fine).
5. Click on **Show more** within the **Category total** section. Find the **Grade type**
   section and choose **None**.
6. Scroll to the bottom of the screen and click on **Save changes**.

Any graded activities that are listed in this category will not be included in the
course total aggregation.

You can also create the same effect by creating a category with a category total of zero.

*Organizing the Gradebook Using Categories*

If you would like to keep the formative assignment and the summative activities within
the same category rather than keep all the formative work in a separate category, a
subcategory can be used. This enables the graded items to appear together within the
Gradebook, but they are not counted in the course total grade. To achieve this:

1. Go the **Grades** area and then go to the **Categories and items** page.
2. Go to the parent category (where you will be adding the subcategory)
   by clicking on the edit icon next to the category name.
3. Make sure that there is no tick next to **Aggregate including sub-categories**.
   It is worth mentioning here that if you are using subcategories and want the
   grades to be included in the course total, you will need to go into the parent
   category and check this option.
4. Click on **Save changes** at the bottom of the screen.
5. Scroll to the bottom of the screen and click on **Add category**.
6. Give the category a name (such as formative assessments or not used
   for final grade).
7. Make sure the aggregation is not sum of grades (any other aggregation
   method is fine).
8. Click on **Show more** in the **Category total** section and find the **Grade type**
   section and choose **None**.
9. At the bottom of the screen, click on the drop-down list next to **Parent**
   category, and choose the **Parent** category that you created previously.
10. Scroll to the bottom of the screen and click on **Save changes**.

Anything moved into this category will not be included in the course aggregation,
but it will enable the assignment to be viewed within the Gradebook with the
relevant parent category.