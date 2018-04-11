This repository contains milestones from ECE3574 at Virginia Tech.
The course objectives are as follow:

-Use software design patterns and application programming interface (API) specifications to implement efficient and portable         software.

-Design and implement multi-threaded and multi-process applications that rely on standardized inter-process communication and synchronization mechanisms.

-Design and implement complex software applications based on portable software frameworks and event-driven programming.

-Design, implement, and perform testing strategies including unit and integration testing.



The first milestone simply reads note, amplitude, and duration from csv files and converts each csv file to .wav file

In second this milestone, instead of reading the notes,amplitudes and durations from .csv files, it reads
event from .mid files and distinguish the events and change data accordingly to convert them into .wav files

The third milestone involves GUI development, where the additional data (velocity,attack time, decay time,etc) is controlled by user.

The fourth milestone involves multithreading where multiple events can happen at the same time. The project involved implementation of message queue and double buffer, 
which required usage of mutex and condition variables. 
