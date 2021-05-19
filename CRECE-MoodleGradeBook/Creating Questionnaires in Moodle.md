# Creating Quizzes in Moodle

```
NOTE FOR SPANISH SPEAKERS: Si la interfaz del Moodle está en castellano, la tradución de "cuestionario" (quiz en inglés) es _prueba_ o _examen_. Hay que íjarse bien en esto a la hora de elegir esta actividad porque existe un "Cuestionario" en la interfaz en castellano, pero é un módulo para facer encuestas, y es adicional.  
En Español internacional decidieron llamar _cuestionario_ como traducción de la palabral inglesa quiz, y que en el Español de México, por ejemplo,  se llama Módulo de examen. Puede cambiar de unos países de habla hispana a otros. Lo que vamos a tratar en esta sección es el módulo estándar __Quiz__ que utiliza (aunque no es obligatorio_ el banco de proguntas (Question Bank) como soperte y no es un "plugin" o módulo adicional de Moodle sino forma parte del núcleo estándar. 
```

This guide is a short tutorial to the use  Moodle 3.x Questionnary Module Design Tool. This module allows teachers to create a wide range of questions to get student feedback e.g. on a course or activities, but it is a plugin so, may be you have to ask your system administrator to install or enable the module.

The goals of the Quizz module are quite different from those of the Moodle Lesson or Quiz modules. With Questionnaire you do not test or assess the student, you gather data.

## Quizzes

A quiz is an moodle activity than can be reached as follws:

Main page `>`  Managing a Moodle course `>` Activities `>` Quiz module

The Quiz is an activity that can meet many teaching needs, from simple, multiple-choice knowledge tests to complex, self-assessment tasks with detailed feedback. Questions are created and stored separately in a Question bank and can be reused in different quizzes.

When creating a Quiz you can either make the questions first and add them to the Quiz, or add a Quiz activity (as below) and create the questions as you go along.

The logical way of use is to create (and) manage questions in the _Question bak_ (_banco de preguntas_)  

### Features of the Question bank

Quizzes can be configured to allow multiple attempts. Each attempt at a question is automatically marked, and you can choose whether to give feedback and/or show the correct answers.
There are many ways to use a quiz.

* Feedback about performance and self-assessment are important parts of a learning environment. There are several ways to give feedback to students: 
  * On each question 
  * Overall feedback
* The quiz module can display feedback and scores at different times during the quiz (using the _review_ option in the _Quiz_ settings).
* A wide variety of _Quiz reports_ (in addition to Grades) are available for your use. _Quiz reports_ not only can focus on a single student's attempt, but also can perform a robust item analysis of a question's aggregated responses.
* A single quiz can automatically marked as _random_ and/or _specific questions_ from different categories.
* There are different options for scoring individual questions in a specific quiz, grading attempts for a quiz and question type.
* The quiz settings allow different display methods:
  * Randomize questions for each student
  * Randomize answers for each student.
* You can determine the number of questions on each page of questions an change the position of any question in the quiz. It is possible to write a label with information anywhere between questions.
* You can choose how questions behave during the quiz:
  * Like a classic test, where the student gets no feedback while attempting the test, only later.
  * Alternatively, Moodle can reveal the grades and/or feedback to the student during the quiz, and perhaps even give them another chance to answer the question (for fewer marks) having read the feedback.

## The question bank

Questions are stored and grouped into categories in a repository denoted as _Question bank_.

We can find the _Question bank_ in the menu on the right, clicking on "more..", if we can't seeit as a visible option:

<img src="./images/fig1.png" alt="Question bank" style="zoom:50%;" />

The question bank option appears on the following screen (it is a menu section in the _Moodle course administraqtion_ menu):

<img src="./images/fig2.png" alt="Question bank menu" style="zoom:50%;" />

## Using the Question bank

Questions in Moodle are organized into _categories_. A new course starts out with one category named "Default for [course name]." To make it easier to find questions, and to facilitate the use of random questions, you can organize your questions into additional categories. You can create a hierarchy of categories by creating subcategories inside parent categories. The more organized you make your question categories during the initial setup of your course, the easier it will be to reuse questions in future quizzes and exams.

**Add & Manage Question Bank Categories**

To do this:

| Step | Actions                                                      |
| ---- | :----------------------------------------------------------- |
| 1.   | On your course page, select the _Course Management_ (black gear icon, top right), a *Course Management* panel will open. |
|      |                                                              |
| 2.   | On the panel, under *Quiz Questions*, click _Question bank_. The _Question bank_ page opens to the *Default category* for the course you are in, and on this page you will also see Questions, Categories, Import and Export tabs. |
| 3.   | To add a new category, select the **Categories** tab. The *Edit categories* page will open. |
| 4.   | On the *Edit categories* page, under *Add category*, define the new category that you want to add: |
|      | **Parent Category** (Optional)  Select a:<BR>   **Parent category** for the new category. (By default, the new category will be added as a sub-category<BR>   of   the course's default category.).<BR>   **Name** (Required)  In the *Name* field, enter a name for the new category.<BR>   **Category info** (Optional)  Enter a description for the new category in the *Category info* field. |
| 5.   | Click **Add category** to add the newly specified category.  |
| 6.   | (Optional) To delete, edit, move, or indent a category, click the **configuration icons** next to each |

**Add Questions to a Category**

You can add questions to a category by creating new questions within a category or moving questions you have already created from one category to another. You must create categories before you can populate them with questions:

| Step | Actions                                                      |
| ---- | :----------------------------------------------------------- |
| 1.   | On your course page, select the **Course Management** (black gear icon, top right), a *Course Management* panel will open. |
| 2.   | On this panel, under *Quiz Questions*, click **Question bank**. The *Question bank* page will open. |
| 3.   | **Select a category** from the S*elect a category* drop-down menu. The page will update to show you the list of questions within thatcategory. |
| 4.   | Next, select **Create a new question...**. The *Choose a question type to add* window will open. |
| 5.   | Choose the **type of question** you want to add, then select **Add**. The *Adding a Question* page will open. Configure the questionaccording to its type. |



To move questions from one category to another:

| Step | Action                                                       |
| ---- | ------------------------------------------------------------ |
| 1.   | On your course page, select the **Course Management** (black gear icon  								, top right), a *Course Management* panel will open. |
| 2.   | On this panel, under *Quiz Questions*, click **Question bank**. The *Question bank* page will open. |
| 3.   | **Select a category** from the *Select a category* drop-down menu that contains the question or questions you want to move. The page |
| 4.   | **Select the question(s) you want to move** by clicking the check box to the left of the question(s).<br>   **Note:** You can select/deselect all the questions in a category by selecting the check box at the top<br>   left of the questions table (to the left on the T). |
| 5.   | On the bottom of the page, in the *Move to >>* drop-down menu, select a category you want to move the questions to. |
| 6.   | Next, select **Move to >>**. The page will refresh to display the destination category with all questions in it. |

## Export Quiz Questions

To export questions from Moodle, one category at a time:

1. On your course page, select the **Course Management** (black gear icon  								, top right), a *Course Management* panel will open.

2. On this panel, under *Quiz Questions*, click **Question bank**. The *Question bank* page will open to the *Default category* for the course

   you are in. On this page you will also see Questions, Categories, Import and Export tabs.

3. Select the **Export** tab. The *Export questions to file* page will open.

4. Choose a **file format** (Gift, Moodle XML, or XHTML). Gift and XML can be imported to Moodle or other Learning Management

   Systems. XHTML will open as a Web page in a browser, or can be opened in a word processing application such as MS Word.

5. Under *General*, from the *Export category* drop-down menu, choose a **question category** to export from.

6. Click **Export questions to file**.

### Categories

A _category_ is a logical grouping of questions. Initially there is a category "Default for", but you can create as many as you want. Since then, all questions on a topic or activity are stored within a category. This will make the search and retrieval easier and fast.

```
Have the question bank organized by categories, allows you randomize the questions selected by moodle from each category. For example, if we have a bank of categorized questions (e.g. 50, grouped in 5 categories), we can design a quiz using only we need (e.g. 20 questions chosen at random, being 4 from each of the 5 categories we have defined)
```

To create a category:

You can imagine a question category as a folder on your desktop computer. Then, questions are stored in these categories in a similar way as your files are stored in a file system.

<img src="./images/fig3.png" alt="Question bank menu" style="zoom:50%;" />

Each category must have a name and you can include a short description of the category. You can create a category hierarchy. For example, you can specify a parent category for each category or the 'Top' as the parent, when a category has no parent. 'Top' is not really a category. It just a parent for all the top-leve categories. It exists so that, when you are adding questions to the quiz, you can select it as a way to get any question.

Tip: Creating question categories and sub categories is a good practice. It is better than keeping all your questions in one big list in the quiz module. The hierarchy feature enables you to separate categories into sub categories and sub categories into sub sub categories etc. indefinitely. Categories and sub categories, etc., are very powerful when combined with random questions that can select either from one category or from a category or any of its sub categories.

At the top we will see a list of existing categories in the
course. You will see at least one category listed with the name
"Default for: * short course name *" (where short course name
is the course code), and then in parentheses the number of
questions contained in the said category. If no new categories are created,
all questions will belong to the default category.

To create a category, go to "Add category", we indicate which will be
the main category in which it will be created, we type a name and click
in "Add category":

### QUESTIONS

Once the category is created, you can create the questions for the new category.

From the "Questions" tab, under "Select a category" choose a
category in which you are going to insert the question and "create a new question":

* Guide to creating questionnaires in MooVi *

MooVi allows you to create many different types of questions:

* Guide to creating questionnaires in MooVi *

#### Multiple choice

One of the most used types is the question "** Multiple Choice **". For
create one, click on the "Create a new question" option and select the
type "** Multiple Choice **". On the next screen, enter:

- Name of the question: it is not the statement, if not the name with which it goes
  appear within the question bank, so it is important that
  write something that is meaningful when it comes to locating it in the
  future.
- Question text: the statement, may include images, links,
  formulas, videos etc.
- Default score: weight on the total score in the
  test. You will also be able to provide the score to the question further
  forward.
- General comments: you can put information that will appear to the
  students in the revision of the exam.
- One or more answers ?: allows you to specify if the question has
  one or more correct answers.
- Shuffle the answers ?: if you check this option, test the answers
  will be displayed disordered. If you want to show them in the order in the
  that you believe them, you must leave this option unchecked.
- Number the choices ?: choose if you want the answers to go
  numbered with letters, numbers etc.

It then provides the answers to your question, both
correct as well as incorrect and the qualification of each of them. Yes
you want to give a negative rating to the wrong answers,
advances in the drop-down.

`` `
The multiple choice question type is the only one that allows
rate a response negatively.
`` `

If you select "** None **", you are indicating that this is not the correct answer,
but without assigning a negative score if the student selects it.

`` `
Don’t forget to give the 100% score to the correct answer
in case there is only one correct, or the percentage that
`` `

* Guide to creating questionnaires in MooVi *

`` `
you want to assign to each answer in case there are more
of one that is correct.
`` `

For each answer you can add the information in the "comments" box
which will be visible to the student if that answer is selected.

There is another section so you can provide information to
students, "** Combined comment **", with each answer given by
its band (correct, partially correct, incorrect). This information,
like the rest of the comments that can be configured, will be displayed to
students once the test is over (and depending on how we have
configured the visibility of the quiz review options).

`` `
You can allow students to make multiple attempts at
answer to the question you are creating, but this
configuration will only be valid if you configure the test
selecting an Interactive behavior with
multiple attempts, Adaptive mode with penalty
or Adaptive mode without penalties.
`` `

For any of these cases, in this section of "Multiple Attempts",
select in "Penalty for each incorrect attempt" a
percentage with which you want to penalize students every time they fail
an answer and try again: for each attempt you will accumulate
negative score that will be subtracted if the correct answer is provided in
next attempt. Only create an exam “Interactive with attempts
The tips you can create in the following tables will be valid
text: depending on the number of tips you give to students,
you can try this question again. If you create two tips, you can
try to answer twice and you will be penalized with the percentage you have
specified in penalty.

`` `
Don’t forget to save the question by clicking the button
"Save changes."
`` `

* Guide to creating questionnaires in MooVi *

#### Practice

Another type of question that we will dwell on is the "practical" type question.
(* essay * in Spanish), as it is a little different from the other questions.
This type is not self-assessable, as what is required is that students
respond by submitting a file or writing to the editor. This question has
to be qualified manually by the teacher.

The first configuration parameters are similar to the rest (choose
the "Category" to which it belongs, write the name and text of the question,
default score and general comments ^ 1).

- Answer format: select the format in which the student should
  answer the question. The "no online text" option is only possible
  answer by attaching one or more attachments.
- Require text: if “HTML Editor” was selected in the previous option,
  can be checked if text writing is optional or required.
- Inbox size: Select the number of rows in the box
  of response.
- Allow attachments: number of files that can be sent.
- Require attachments: how many files are required.
- Accepted file types: the accepted format types
  can be restricted by entering the file extension (s).
- Response model: you can insert a response model that is
  it will show in the answer box and it serves as a guide.
- Information for qualifiers: information for qualifiers can be included
  the people who will qualify the practice.

`` `
Don't forget to save the question by clicking on the "Save
changes ».
`` `

### 2. CREATE AND SET UP A TEST

Once the categories and questions for the test have been created, we return to the
central part of the course. To add a test, you must "Enable Editing"
and click “Add an activity or resource” in the section

(^ 1) For more information see the previous section on "multiple choice".

* Guide to creating questionnaires in MooVi *

corresponding and select "Test" ("Questionnaire" if you have the interface
in Spanish):

This will take us to the configuration form, where we will complete one
series of fields.

- In the field «Name» we write the title with which we want it
  the questionnaire appears on the main page of the course. We write
  also a short description.

`` `
Use the description of the test to make it easier for you
students that information they must know prior to
start the attempt. For example, the number of attempts that
has, the qualification method, if there is a time limit for
perform it etc.
`` `

*** Sync \ ***

- Open the test. If we activate this option we can specify a
  date from which the questionnaire will be accessible to the
  student.

* Guide to creating questionnaires in MooVi *

- Close the test. If we activate this option we can specify a
  closing date of the activity from which the student does not
  you will be able to access the questionnaire.
- Time limit. If we activate this option we can specify,
  in minutes, a time limit for completing the questionnaire.
  Usually this limit is not set and students can
  take the time they wish to answer the questionnaire.
- When the term expires: we can configure the behavior of the
  questionnaire when the student runs out of time to send it.
  We have three options available within the drop-down menu: os
  open attempts are sent automatically; there is a period
  during which an open attempt may be delivered, but not
  answer more questions (this period is set out in the following
  configuration parameter); attempts must be delivered first
  of the expiration of the term, or will not be counted.

`` `
We recommend that you choose the option “open attempts
they are delivered automatically ”, since when the time of the
exam ends, answers are sent automatically,
even if the student does not click on the button «Send all and
finish ».
`` `

- Delivery grace period: if we activate this option in the field
  above, we can set the maximum limit to send the
  questionnaire in weeks, days, hours, minutes or seconds.

*** Qualification \ ***

- Qualification category: and this menu allows us to select a
  qualification category we want, within the created
  previously, to incorporate it into our activity or task.
- Qualification to pass: allows to visually identify the
  students who passed the exam in the grade table,
  marking in green those who passed and in red those who did not.
- Attempts allowed. Sets the number of times that
  students can take the exam, from an unlimited number
  sometimes (it is the default value) up to a maximum of ten attempts.
- Qualification method. This option allows us to choose between
  various grading methods: highest score
  (qualifies the questionnaire with the highest mark achieved in

* Guide to creating questionnaires in MooVi *

`` `
any of the attempts made); average grade (the grade
end will be the average of all attempts); first attempt (a
final qualification will be the one obtained in the first attempt); last
attempt (the final grade will be the one obtained in the last attempt).
`` `

*** Design \ ***

- New page: this option is used to configure the questionnaire and
  the number of questions per page. We have two options:
  o That all questions appear on the same page,
  then in the drop down menu we must select the option
  "Never, all the questions on one page."
  o Specify the specific number of questions that will appear
  on each page.

`` `
This configuration is not immovable; within the management of the
quiz we can also create or delete pages.
`` `

- Navigation method: we can set the order in which the
  students must browse the quiz and we have two options:
  o Free: students can navigate as they please within the
  questionnaire.
  o Sequential: when sequential navigation is activated
  student must advance through the questionnaire in one order
  determined and cannot return to previous pages nor
  jump forward.

`` `
Note that if you select the sequential method the
students are advancing without the possibility of returning to
previous pages or jump forward.
`` `

*** Question behavior \ ***

- Shuffle within the questions: if you enable this option, the parties
  which make up the individual questions will be sorted at random
  each time a student begins to answer the
  questionnaire, assuming the option is also enabled in the
  question settings. This option only applies to questions that

* Guide to creating questionnaires in MooVi *

`` `
they have multiple elements, such as choice questions
multiple or pairing.
`` `

- How the questions behave: this option is related
  with the way the student interacts with the questionnaire and the type of
  information that the student will be able to see after the attempts of
  solve the questionnaire.

`` `
It is important that you pay attention to the different types of
test behavior
The types of behaviors we can establish are:
Interactive with multiple attempts: after answering and pressing the
"Check" button to validate, if this is incorrect the student
you must press the "Retry" button before replying again.
Each question will have as many attempts at possible answers as clues
the teacher wrote. By default all questions have a try
at least. The students, once they reach the maximum of attempts
allowed by the question, if an incorrect answer is given no longer
you will be able to correct.
Adaptive mode: will allow the student to give several answers to
a question even in the same attempt and one will be applied
penalty that will be deducted from the total score for each attempt
wrong (the amount of penalty is determined by the “Factor
of penalty ”, established in the configuration form of each
one of the questions). Special care must be taken when using them
questions that need to mark several answers, as the possibilities
of partial qualification are extended. It is necessary to review especially the
qualification and the penalties offered for these responses.
An example of this type of exams are the tests with
penalty, in which the student who scores is penalized
incorrect answers with a penalty in each of the
checks you perform.
Adaptive mode without penalties: works the same as in the case
previous; will allow the student to give several answers to one
asks even in the same attempt to solve the questionnaire, but
`` `

* Guide to creating questionnaires in MooVi *

`` `
no penalties. So, for example, if the answer is incorrect, the
student can give another answer immediately without being subtracted
no point.
An example of this type is self-assessment tests.
Deferred Comments: Review and results of questions
they are performed once we have finished and submitted the questionnaire. In this
questionnaire type are not penalized neither the wrong answers nor the
left unanswered.
This is the type of exam in which students will be offered a
note at the end of the test. Students cannot check
your answers nor display any kind of
feedback until the attempt is complete.
Deferred comment with PCB: with the PCB the student does not only respond
the question, but it should also indicate what level of confidence
has in that the answer given is correct. The rating is adjusted by
choice of certainty, because students must reflect with
sincerity your own level of knowledge to achieve the
best note.
Immediate Comment: It is similar to “Interactive with Attempts
multiple ». The student can send their answers in a way
immediate and be scored, but in this type can give a unique
answer, which cannot be changed later.
Immediate comment with PCB: is similar to «Deferred comment with
PCB », but the student can give a single answer that he / she will not be able to
change later.
`` `

- Each attempt is built on the last: if several are allowed
  attempts and “Yes” is selected, each new attempt will contain the result
  of the above. That is, when the student makes several attempts to
  complete the questionnaire, you will find the answers given previously.
  In order not to show the previous answer in each attempt,
  we select "No".

* Guide to creating questionnaires in MooVi *

*** Review options \ ***

These options control what information any student can see
after his attempt to solve the questionnaire (after pressing «Send all and
end »). We can decide that it will be exactly what the
student can see: answers, scores, comments, solutions or
general feedback.

`` `
We must keep in mind that some of these options will be
marked by default according to the behavior type of
questions we marked in the previous point.
`` `

The temporary options offered to review the test are:

- During the attempt: the review can be performed at the same time
  in which each of the questions is answered.
- Immediately after the attempt: the review can be done,
  approximately, during the two minutes following the
  attempt and only once; that is, if nothing else ends the
  questionnaire the student reviews, even if they do not pass both
  minutes of margin you will no longer be able to review it more often.
- Then, while the test is still open: the review of the
  questionnaire can be conducted after two minutes of your
  realization, at any time before the closing date. Yes
  there is no questionnaire closing date, activating this option
  the review may always be performed.
- After the test is closed: the review can be performed
  once the closing date of the questionnaire has passed (you do not have
  sense use this option if the questionnaire is not dated
  sin).

Regardless of when students review the questionnaire,
each option we mark will offer you different data on this one.
The following is what you will see when you select only one option:

- The attempt: if we select this option, the student, once
  that you give the "Send All and Finish" button, you can see the
  attempt made.
- When correct: with this option in addition to seeing the attempt again
  you will be able to see if the answer is correct or incorrect.

* Guide to creating questionnaires in MooVi *

- Scores: the student will find a table with the number of
  attempts, the date of completion of the questionnaire and the comment on
  white (refers to the "Global Feedback" located at the end of the
  list). In addition, a section called will appear
  “Qualification” in which they will find their grade, taking into account the
  value granted.
- Specific comment: shows specific feedback that
  we gave each of the question answer options.
- General comments: this section refers to feedback
  concrete included in the field of the configuration form of
  every question. Unlike the comment for the answer, in this one
  the same text is always displayed in all cases.
- Correct answer: if we activate this option during the review,
  we will be shown a message with the correct answer to each one
  of the questions.
- Full feedback: if we select "Full feedback",
  located at the end, the students see a table with the number of
  attempts, the date of completion of the questionnaire and the comment.
  In this section "Comment" appears the message that
  we introduce in the total feedback of the general configuration of the
  questionnaire, referring to the grade obtained by the student in it.

*** Appearance \ ***

- Show user image: if we check this option is displayed
  the image of the user who is completing the questionnaire.
- Decimal positions in the tables: using this option
  we will set the minimum number of decimals present in the
  qualification.
- Decimal positions in the question tables: in this field
  we will set the number of decimals that will appear in the
  qualification of each of the questions. We can select
  the “Same for general grades” option or select
  another number in the drop-down menu.
- Show blocks during test attempts: this option
  allows us to remove blocks from the course so that during the
  completion of the questionnaire only the questionnaire appears.

*** Safe Exam Browser \ ***

This is a new feature in Moodle version 3.9. This is a
custom internet browser, available for operating systems

* Guide to creating questionnaires in MooVi *

Windows (7, 8.1 and 10) and Mac (from 10.7, 10.11 or higher is recommended
recent) and for iOS (9.3.5 or later), which must be downloaded and
install on the device that the student will use when trying to answer one
questionnaire. Restrictions for students are similar to the case of
pop-ups, but because * Safe Exam Browser * is software
who runs on the student team, can perform more effective work
to restrict his actions, among others:

- Students can only pass the exam if they are using it
  * Safe Exam Browser *.
- The browser window will not have a URL or field to
  search, or forward or backward navigation and you can
  disable reload page.
- The * Safe Exam Browser * cannot be closed until the
  exam.
- Switching to another application is disabled by default,
  but it is possible to allow the specific use of
  third parties during an examination.
- The clipboard is cleaned when starting and leaving * Safe Exam *
  * Browser *.
- The browser context menu is disabled.

The available options are:

- * No *: does not require "Safe Exam Browser" to perform test (by
  defect).
- * Yes - Configure manually *: No template will be used for
  Safe Exam Browser settings. You can set it up
  manually.
- * Yes - Upload my own config *: you can upload your own config file
  Safe Exam Browser settings. All manual adjustments and
  the use of templates will be disabled.
- * Yes - Use SEB client config *: no Safe Exam settings
  Browser »on the Moodle side.

`` `
Learn more about this new feature at:
https://www.youtube.com/watch?v=ytztYguXixk
`` `

*** Extra restrictions on attempts \ ***

* Guide to creating questionnaires in MooVi *

- Requires password: if we want we can set one
  password so that, to access the test, the students
  they must introduce it. This password will be displayed at first
  with asterisks.
- Requires network address: allows you to specify computers
  concrete from which it will be possible to carry out the questionnaire to the
  identify them by their IP address.
- Forced waiting between the 1º and the 2 é attempt: it is the time that each
  student will have to wait before being able to answer the
  questionnaire after the first attempt.
- Forced wait between the last attempts: here we can
  set the time we want to elapse until the
  student can answer the questionnaire by third or more
  times.
- Browser security: allows you to open the quiz in one
  window in which security is higher, for which they are restricted
  some of the operations that students can perform with
  your browsers.
- Allow the test to be attempted offline using a
  mobile application: if enabled, students using a
  Mobile application can download the test and try it offline.

*** Total feedback \ ***

It allows you to enter a total feedback that is shown to the students
students once they have completed the questionnaire. The text shown is
different depending on the qualification they obtained. For that we can
set different qualification limits, which define ranges of
rating, and different comments for each limit. In this way
different comments will be displayed depending on whether the grade obtained by the students
students fall within one or the other range.

The rest of the sections are common to all resources and activities. By
default, the test will be visible to all those enrolled in your subject,
but you can add visibility restrictions for groups in the section
"** Restrict access **". You can also select in the section «** Completed
of the activity ** »under what conditions the exam will appear as completed
within the activity completion report.

* Guide to creating questionnaires in MooVi *

### 3. ADD QUESTIONS TO THE EXAM

When we set up a test and save the changes, it takes us to one
page stating that "No questions added yet." We have
to give you the "Edit Test" so you can add the questions that
we previously generated in the question bank. The option to “Edit
test »can be found on that screen but also in the
right settings:

On the next screen, you can select questions from the question bank
previously created, you can create new questions by adding them
directly to the exam and in addition you can order them as you wish and
add a rating.

Clicking on the "Add" button opens a menu that allows you
add “a new question,” “from the question bank,” or “one
random question ”(this last option is explained below):

By selecting "from the question bank" you will see a pop-up window with
list of question categories you created in the question bank.
Select the category you want and you will see all the questions that
creaches. You will be able to select questions individually or in whole
category at once. Click the "Add Selected Questions to" button
test »to incorporate the questions:

* Guide to creating questionnaires in MooVi *

Once added, you can distinguish several columns that allow you
perform different actions on the questions:

- A vane to move the questions
- The identifier of the type of question
- The settings button to modify the question
- The name and the statement of the question
- A magnifying glass to preview the question
- The trash can to remove the exam question
- The qualification of the question within the exam

Add the maximum exam grade and don’t forget press the "Save" button to store
exam settings.
`` `

#### Exame from random questions

Moodle also allows you to create a quiz with random questions, selecting a random number of questions from one or more categories. In this way, each student will have a combination of different questions.

To create a random test, select from the drop-down that displays the "Random Question" option in "Edit Test":

*  window will open in which you can select the category of your bank
  questions and you only need to indicate the “Number of random questions” that
  you want them to be included in that category. Click on the button "Add one
  he asks at random.

At the end, you can check how your test was created.
Select the "Preview" option from the
Test administration.

This is an offline tool, your data stays locally and is not send to any server!

[Feedback & Bug Reports] (https://github.com/jzillmann/pdf-to-markdown/issues)
