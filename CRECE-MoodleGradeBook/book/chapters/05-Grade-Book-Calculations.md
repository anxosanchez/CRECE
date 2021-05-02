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

*Using Calculations*

### Example one – The mean of grades

In this example, three assignments have been added to the Moodle course. Two have
a maximum grade of 100 and one has a maximum grade of 50. If you want to follow
the instructions to set up an example Gradebook, create three assignments and
choose 100 as the maximum grade for **Task 1** and **Task 2** and 50 for **Task 3**. Grade
**Task 1** and **Task 2** for at least one learner. In the following example, you can see
activities we use:

The aggregation type of this course will be the mean of grades, which will present a
final average grade.

Let's go into the **Grades** area and choose the aggregation type:

1. Click on the **Administration** block and then click on **Grades**.
   You should see a table like the previous one, which will show you the grades
   of each assignment for each student. If you see an overall average row at the
   bottom of the screen, don't let it confuse you. This is an average grade based
   on all the students in the course rather than an individual student's average
   grade, and it is shown for all aggregation types. You will learn more about
   customizing this screen in *Chapter 7, Reporting with the Gradebook*.
2. From the drop-down list at the top of the screen, find **Categories and items**
   and choose **Simple view** (or click on the **Categories and items** tab if your
   screen shows the tabs view).

This is where we can start to customize the Gradebook and choose the
aggregation type.

You can see that the **categories and items** screen is another table with column
headings that explain the content of the table. You can change the aggregation of the
course from the drop-down list in the aggregation column. Click on the drop-down
list box and choose **Mean of grades** , then click on **Save changes** at the bottom of the
screen. This is not the only way to change the aggregation type, and we will look at
other ways of doing this later in the chapter.

Take a look at the **Max grade** column. This shows you the maximum grade possible
for each graded item in the course and the course total, which is the number at the
bottom of the table, shows you the total final grade possible. In this example, the
course total is displayed as 100 as this is the default (except for the sum of grades
aggregation type), but it can be easily changed by typing an alternative number
into this course total box.

Let's switch back to view the Gradebook. In the drop-down list at the top of the
screen, find **View** icon and click on **Grader report** (or click on **View** on the tab
at the top of the Gradebook screen).

Before we look at other customizations possible, let's take a quick look
at how the aggregation will work in this example. Remember, for this
example, we are using the mean of grades aggregation type, and this type
of calculation converts the grades to a normalized score, adds them all
together, and divides this normalized total by the total number of graded
items in the course. Finally, this is multiplied by the course total—in this
case, 100—to provide the final score.

Take a look at the following screenshot and you can see the **Course total** that shows
you the mean grade for each student:

Take a look at the information of **Bayley W** , who has completed two assessments that
have been graded. His current course total is **95.50** , which could be this calculation:
*91.00 + 100.00 / 2* (that is, the two assignment grades added together and divided by
the total number of grades added together). However, this only works because the
course total is the same as the assignment maximum grades. If the course total was
50, we could not have performed this simple calculation for the course total. This
is why Moodle first normalizes grades and then multiplies this by the maximum
course total possible. So, the calculation that Moodle is actually doing for **Bayley W**
is shown in the following table:

| Task |





 Task 1 | Task 2 Total Mean
aggregation
Final grade
shown in the
Gradebook
Maximum
grade
possible

```

100 100
Grade
awarded
91.00 100.00 191 95.50
Normalized
grade
0.91
(91/100)
1
(100/100)
1.91
(0.91+1)
0.955
(1.91/2)
95.50
(.0955*100)
Chapter 5
```

As you can see, only the assessments that have actually been graded are included in
the aggregation for the course total. So, the student is given a current grade based
on work that has already been completed. However, what if you want to provide
a running total? What if you want the students to know the final grade they will
get based on the work completed to date even if it is not complete yet? This is
particularly important if all assignments need to be completed in order to complete
the course and gain a final grade.

### Including all graded activities

We can tell the Gradebook to include all the graded activities in the aggregation.
Moodle will add up each assessed activity, which will include a zero score for each
assessed item that has not been submitted or graded yet, and then it will divide the
grade by the total number of assessed grades in the course regardless of whether
they have been graded or not. In this example, it will be divided by three. Let's go
and apply this and see it in action:

1. Go to **Categories and items** again (either by clicking on the drop-down list
   and clicking on **Simple view** under the **categories and items** heading or
   by clicking on **Categories and items** in the tabs bar).
2. In the top row in the **Actions** column (in the same row as the aggregation
   drop-down list), the first icon is an edit icon (a cog icon for the default
   Moodle theme; if you hold your mouse over the first icon, it will give
   you a screen tip that says edit). Click on the edit icon.

We are only going to use the **Grade category** section for now. However, the options
that we need are not shown on the screen so we need to click on **Show more** :

*Using Calculations*

Note that you can change the aggregation method on this screen. However, the
setting we need to change is the **Aggregate only non-empty grades** option. Notice
that this box is currently checked. Click on the box to remove the tick and scroll to
the bottom of the screen to go to **Save changes**.

```
This option can be applied with any aggregation type (except the sum
of grades) by clicking on the edit icon in the Actions column on the
Categories and items screen.
```

Let's take a look at the Gradebook again to see what difference this has made.
(To go back to the Gradebook, use the drop-down list at the top of the screen,
find **View** , and click on **Grader report** or click on **View** in the tab at the top
of the Gradebook screen.)

```
Chapter 5
```

You can see that the course total has now changed as it is including all the graded
items in the aggregation. The fewer items that have been marked the lower the grade
will be. The calculation that is taking place for **Bayley W** is now as follows:

```
Task 1 Task 2 Task 3 Total Mean
aggregation
Final grade
shown in
Gradebook
Max grade
possible
100 100 50
Grade
awarded
91.00 100.00 0 191 63.67
normalized
grade
0.91
(91/100)
1
(100/100)
0
(0/50)
1.91
(0.91+1+0)
0.6367
(1.91/3)
63.67
(.06367*100)
```

We have been using the mean of grades, but there are two other mean
aggregation types.

Let's keep using this example but change the Gradebook to show **Simple weighted
mean of grades** and the **Weighted mean of grades** to see how they affect the final
aggregation. This will also give us the chance to practice how to change aggregation
types within the course.

#### The simple weighted mean of grades

In the mean of the grades aggregation type that we have been using, the totals for
each assignment type are not taken into consideration in the final aggregation (other
than for the normalization process). It is only the grades that are used. However, in
the simple weighted mean of the grades aggregation type, the maximum grade of
each assignment is very important. This aggregation type uses the assignment totals
in the mean aggregation step of the calculation.

Let's change the aggregation of the course and see what it does to the final grade:

1. Go to **Categories and items** again (either by clicking on the drop-down list
   and clicking on **Simple view** under the **categories and items** heading, or by
   clicking on **Categories and items** in the tabs bar).
2. Change the aggregation type to **Simple weighted mean of grades** with the
   drop-down list in the **Aggregation** column, and click on **Save changes** at the
   bottom of the screen.
3. Now, switch back to view the Gradebook. On the drop-down list at the top of
   the screen, find **View** and click on **Grader report** (or click on **View** on the tab
   at the top of the Gradebook screen).

*Using Calculations*

Note how the course total score has changed. Look at **Bayley W** again. His previous
score in the mean of grades aggregation was **63.67** (remember that the Gradebook is
currently using all the assessed activities in the calculations and not just those that
have been marked and graded). His score is **76.40** now.

The calculation used in the simple weighted mean of grades is shown in the
following table:

```
Task 1 Task 2 Task 3 Total Mean
aggregation
Final grade
shown in the
Gradebook
Maximum
grade
possible
100 100 50 250
Grade
awarded
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

As done previously, the grade awarded is normalized. However, in this aggregation
method, this normalized grade is multiplied by the maximum grade possible for
the assessed activity. (In theory, the normalization process is not required in this
aggregation type, as the normalization and weighting calculations cancel each other
back to the original grade awarded. However, in practice, Moodle always normalizes
this aggregation type.) However, the calculation of the mean aggregation is different
in this method.

```
Chapter 5
```

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