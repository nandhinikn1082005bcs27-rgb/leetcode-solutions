/* 
Target: Delete rows from p1 where an identical email exists 
in p2 but p2 has a smaller id.
*/
DELETE p1 
FROM Person p1, Person p2
WHERE p1.email = p2.email 
  AND p1.id > p2.id;
