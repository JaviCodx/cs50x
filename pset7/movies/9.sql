SELECT name  FROM people WHERE id IN (
SELECT stars.person_id FROM stars
JOIN movies
ON stars.movie_id = movies.id
and movies.year = 2004)
ORDER BY birth