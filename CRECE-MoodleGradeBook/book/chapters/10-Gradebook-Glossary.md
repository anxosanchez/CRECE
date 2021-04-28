# Gradebook Glossary of Terms

Here are some terms used in the gradebook, both in the development and the user interface. Using these terms in discussions about the gradebook will help to reduce confusion.



| Term                                                         | Definition                                                   |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| Activity                                                     | An instance of an activity module (e.g. a single quiz, assignment etc...) |
| Calculation                                                  | A formula used to calculate grades, based (optionally) on other grade items. Not the same as [Calculated question types](https://docs.moodle.org/dev/Calculated_question_type). |
| Category                                                     | A set of Grade Items. A Category also has its own aggregated Grade which is calculated from its Grade Items. There is no limit to the level of nesting of Categories (a Category may belong to another Category). However, each Grade Item may belong to only one Category. |
| Course completion                                            | The concept of meeting certain criteria for completing a course. In the context of the gradebook, this means a set of grades that must be reached, or a number of outcomes/competencies to complete/master. |
| Grade                                                        | A Grade is a single assessment. It may be a number or an item on a scale (possibly tied to an Outcome). Raw grade value is the numerical or scale grade from activity. Final grade is the grade reported in gradebook. |
| [Gradebook](https://docs.moodle.org/dev/index.php?title=Gradebook&action=edit&redlink=1) | A central location in Moodle where students' Grades are stored and displayed. Teachers can keep track of their students' progress and organise which set of Grades their students will be able to see. Students see their own Grades. |
| Grade Item                                                   | A "column" of Grades. It can be created from a specific Activity or other module, calculated from other Grade Items, or entered manually. |
| [Grade Locks](https://docs.moodle.org/dev/Grades#Locked_grades) | Both whole columns and individual grades can be locked in the gradebook, via the *locked* field. |
| History                                                      | The gradebook has its own type of log, which keeps a History of all changes made to grades. |
| [Outcome](https://docs.moodle.org/dev/Outcomes)              | [Outcomes](https://docs.moodle.org/dev/Outcomes) are specific descriptions of what a person is expected to be able to do or understand at the completion of an activity or course. An activity might have more than one outcome, and each may have a grade against it (usually on a scale). Other terms for Outcomes are *Competencies* and *Goals*. See some [Examples](https://docs.moodle.org/dev/Outcomes_examples). |
| [Scale](https://docs.moodle.org/dev/Scales)                  | A scale is a set of responses from which the teacher can choose one. eg Very cool, Cool, Fairly cool, Not very cool, Not cool |
| Letter Grades                                                | Special representation of grade values similar to scales. Letters are configured in course contexts or above and are defined by lower boundary. eg A (above 90 %), B (above 80 %), C (above 70 %), D (above 50 %), F (above 0 %) |

