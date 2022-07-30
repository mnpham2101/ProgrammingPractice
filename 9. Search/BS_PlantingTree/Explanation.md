# Description:

A tree planting contest is being held. This contest is held in a unique way, and when A employee(s) dig(s) a hole to plant a tree, then B employee(s) plant(s) a tree. They have to plant as many trees as possible during the given N minute(s) to win. Find the maximum number of trees that can be planted.

For the rules of the contest, when a total of N minute(s) is/are given, A employee(s) dig(s) a hole for a certain period of time and B employee(s) plant(s) a tree during the remaining time. The digging ability of A employees may be the same or different. Employee No. i may dig one hole for every Xi minute(s). Likewise, the tree planting ability of B employees may be the same or different. Employee No. i may plant one tree for every Yi minute(s).

There are constraining conditions in that the total time of digging holes and planting trees cannot exceed the given N minute(s), and only the assigned tasks can be performed. In other words, an employee who plants a tree cannot dig a hole and an employee who digs a hole cannot plant a tree. A hole should be dug first and only as many trees as holes dug can be planted. However, a tree must be planted in each hole that is dug. There is no need to calculate the time it takes to rotate between the two groups.

For example, if the given time N is 35 minutes, 3 employees digging a hole are included in group A and 2 employees planting a tree are included in group B, and the information for these two groups is as follows:

If group A digs for 20 minutes, employee No. 0 can dig 5 holes, employee No. 1 can dig 3 holes and employee No. 2 can dig 4 holes, so the number of holes that can be dug will be 12 (5+3+4 = 12).

When group B plants trees for the remaining 15 minutes, employee No. 0 can plant 5 trees and employee No. 1 can plant 7 trees, so the number of trees that they can plant will be 12 trees (5+7 = 12).

Find the maximum number of trees that can be planted according to the given N minutes and the information regarding Groups A and B.

* **Input**
In the first line, the given time N (in minutes) is entered (N is an integer, 1 ≤ N ≤ 109)
In the second line, the number of employees digging holes, A, is entered (A is an integer, 1 ≤ A ≤ 100)
In the third line, time information Xi for A employees separated by a space is entered (Xi is an integer, 1 ≤ Xi ≤ 109)
In the fourth line, the number of employees planting trees, B, is entered (B is an integer, 1 ≤ B ≤ 100)
In the fifth line, time information Yi for B employees separated by a space is entered (Yi is an integer, 1 ≤ Yi ≤ 109)

* **Output**
The maximum number of trees that can be planted for the given N minute(s) is outputted.
