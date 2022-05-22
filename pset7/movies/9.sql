SELECT name
FROM people
WHERE id IN (
SELECT DISTINCT stars.person_id
from stars JOIN movies ON movies.id = stars.movie_id
WHERE year = 2004) ORDER BY birth;