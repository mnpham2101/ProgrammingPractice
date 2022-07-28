SELECT Emp.name  as 'Employee'
FROM Employee as Emp
    INNER JOIN Employee as Mngr 
        ON Emp.managerId = Mngr.id
        WHERE Emp.Salary > Mngr.Salary