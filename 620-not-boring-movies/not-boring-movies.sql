select *
from Cinema
where id % 2 != 0 and description != 'boring'
order by rating desc;


-- SELECT * FROM Cinema WHERE MOD( id, 2) = 1 AND 

-- description <> 'boring' ORDER BY rating DESC