SELECT P.email as Email
FROM Person as P
GROUP BY P.email
HAVING COUNT(P.email) > 1
