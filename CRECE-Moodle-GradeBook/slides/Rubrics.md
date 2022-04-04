---
theme: gaia
size 16:9
paginate: true
header: CBHE-CRECE
footer: University of Vigo
_class: inverto
color: #FFF
backgroundColor: #000
---

# Rubric Grading in Moodle <!-- fit --> 
  

A. Sánchez  

---

# About rubrics

- An advanced grading method used for criteria-based assessment.
- The rubric consists of a set of criteria plotted against levels of achievement.
- A numeric grade is assigned to each level. For each criterion, the assessor chooses the level they judge the work to have reached.
- The raw rubric score is calculated as a sum of all criteria grades. 
- The final grade is calculated by comparing the actual score with the worst/best possible score that could be received.

---

# Do you need rubrics?

- Answer carefully yourself before begin

---

# When use rubrics?

- Assignements as separate files (spreadsheets, pdfs, tex documents. ,etc.)
- Reports (Lab experiences reports)
- Workshops
- Homework

---

# Limitations of rubrics?

- Only for a few assigmnents
- Not available to estudents "a priori"
- Not easily documentable
- Slighly reusable

---



# Enable a rubric in your assignment

- At the point of setting up the Assignment.
- In your assignment's Settings:
    - Expand the Grade section.
    - From the Grading method menu, choose Rubric.

Note the Maximum grade setting - whatever numeric grade you assign to your criteria levels, the ultimate grade for the assignment will be recalculated as the proportion of that maximum grade.
Save the settings; Rubric is now enabled for that particular Assignment.
The other is via the Assignment's Settings block:

From the Assignment's summary page, in its Settings block, click Advanced grading; a new page displays a menu.
From the Change active grading method to menu, choose Rubric; this initiates the rubric setup process.
Define your rubric

A rubric
To define a new rubric from scratch:

Go to the Rubric editor via the Advanced grading link in the assignment's Settings block.
Click Define a new rubric from scratch.
Type in a brief distinctive Name and (if needed) a description.
Click to edit a criterion and Click to edit level lets you tab through the rubric to type a description and assign points to each level.
Describe further criteria and levels as appropriate.
Set Rubric options.
Finally save the rubric definition by clicking Save rubric and make it ready or Save as draft. These set the form definition status respectively as described at the Advanced grading methods page.
Notes:

Unless there is a good reason otherwise, enable Allow users to preview rubric so that they know in advance the standards by which they will be judged. Enabling Remarks allows assessors to make constructive suggestions for each criterion.
Numeric points are required, but if you want to use your rubric to give feedback without a numeric grade it is possible to hide these from students, and hide the final calculated grade from students.
You can enter negative points, for example as a late submission penalty.
You can modify the weight of any criterion by setting the value of the points assigned to its levels. If there is one criterion with levels 0, 1, 2, 3 and the second one with levels 0, 2, 4, 6 then the latter's impact on the final grade is twice as much as the former's.
You can use the Tab key to jump to the next level/criteria and even to add new criteria.
In Moodle 3.2 onwards, a new rubric option 'Calculate grade based on the rubric having a minimum score of 0' allows you to choose whether the grade is calculated as in previous versions of Moodle (box unticked) or whether an improved calculation method is used (box ticked). Please see below for details of the calculation.
Grading submissions with a rubric

Filling in the rubric to assess an assignment submission
To access the submissions, click a link to the Assignment; its summary page displays.
Click Grade; the Student Grading Page displays the work of the first student listed in the Grading Table.
The rubric you have set up will display as a table on one side of the screen - you can display it larger by clicking its Expand / arrowheads icon (to dock the rubric, click the icon again).
For each criterion, select a level by clicking in its cell; when selected the level displays shaded (default pale green).
If enabled on the rubric form, you can type in comments for each criterion.
Save changes.
Notes:

As well as the rubric you can add summary Feedback comments for the work, and optionally Feedback files.
A level must be selected for each criterion, otherwise the rubric is not validated by the server as the final grade can't be calculated.
If the rubric filling is re-edited later, the previously selected level displays temporarily shaded (default: pink).
Students may need to be instructed to scroll down to find the completed rubric and any other comments - the example rubric continues to display at the top of their assignment Submission status page.
Grade calculation
The rubric normalized score (ie basically a percentage grade) is calculated as

{\displaystyle G_{s}={\frac {\sum _{i=1}^{N}(g_{i}-min_{i})}{\sum _{i=1}^{N}(max_{i}-min_{i})}}}
where {\displaystyle g_{i}\in \mathbb {N} } is the number of points given to the i-th criterion, {\displaystyle min_{i}\in \mathbb {N} } is the minimal possible number of points for of the i-th criterion, {\displaystyle max_{i}\in \mathbb {N} } is the maximal possible number of points for the i-th criterion and {\displaystyle N\in \mathbb {N} } is the number of criteria in the rubric.
Example of a single criterion can be: Overall quality of the paper with the levels 5 - An excellent paper, 3 - A mediocre paper, 0 - A weak paper (the number represent the number of points).

Example: let us have an assessment form with two criteria, which both have four levels 1, 2, 3, 4. The teacher chooses level with 2 points for the first criterion and 3 points for the second criterion. Then the normalized score is:

{\displaystyle G_{s}={\frac {(2-1)+(3-1)}{(4-1)+(4-1)}}={\frac {3}{6}}=50\%}
Note that this calculation may be different from how you intuitively use rubric. For example, when the teacher in the previous example chose both levels with 1 point, the plain sum would be 2 points. But that is actually the lowest possible score so it maps to the grade 0 in Moodle.

How students access the rubric

How students view a rubric
Assuming 'Allow users to preview rubric' is ticked (recommended), when students click on an assignment which has a rubric attached to it, they will see the rubric as part of the information about their assignment. Thus, they can see the rubric before they submit.

How teachers access the rubric
Teachers will see the rubric when they click 'View/grade all submissions' and access the work of a particular student. They don't by default see the rubric on the grading page before grading. If you wish to allow teachers to see the rubric, then the site administrator must set the capability mod/assign:submit to 'Allow' for the editing teacher role in that assignment (or sitewide if really necessary). NOTE: This then has the side effect of the teacher appearing in the gradebook.

FAQ
Where do you go to edit a rubric?
To edit a rubric go to Administration > Assignment Administration > Advanced grading > Define Rubric. Select 'Rubric' from Change active grading method to drop down menu. You can see your created rubric with three options above Edit the current form definition, Delete the currently defined form, Publish the form as a new template. Click "Edit the current form definition" to edit your predefined rubric form.

Can you copy rows of the rubric?
A 'duplicate' button allows you to quickly make a copy of a row:

duplicaterubricrow.png
How do you choose another rubric for an assignment?
From Administration>Assignment administration>Advanced grading access your rubric and delete it. The see #5 in Advanced grading methods

Why are total grades coming out strange?
If you are using a criterion without a 0-points level or with a level with negative points, then the rubric option 'When converting rubric score to points/scale assume that minimum number of points is 0' (new in 3.2) should be ticked to avoid unexpected grades.




