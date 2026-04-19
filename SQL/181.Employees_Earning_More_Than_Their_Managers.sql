SELECT E1.name as Employee
FROM Employee as E1
INNER JOIN Employee as E2 on E1.managerId = E2.id
WHERE E1.managerId iS NOT NULL AND E1.salary > E2.salary
