SELECT Person.firstName, Person.lastName, Address.city, Address.state
FROM Person
LEFT JOIN Address on Address.personId = Person.personId
