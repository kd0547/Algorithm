SELECT
    i.ANIMAL_ID,
    i.ANIMAL_TYPE,
    i.NAME
FROM
    ANIMAL_INS i
    INNER JOIN ANIMAL_OUTS o ON i.ANIMAL_ID = o.ANIMAL_ID
WHERE
    NOT (
        i.SEX_UPON_INTAKE LIKE '%Neutered%'
        OR i.SEX_UPON_INTAKE LIKE '%Spayed%'
    )
    AND (
        o.SEX_UPON_OUTCOME LIKE '%Neutered%'
        OR o.SEX_UPON_OUTCOME LIKE '%Spayed%'
    )
ORDER BY
    i.ANIMAL_ID