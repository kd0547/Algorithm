SELECT
    A.APNT_NO,
    P.PT_NAME,
    P.PT_NO,
    D.MCDP_CD,
    D.DR_NAME,
    A.APNT_YMD
FROM
    APPOINTMENT A
    left join DOCTOR D on A.MDDR_ID = D.DR_ID
    left join PATIENT P on A.PT_NO = P.PT_NO
WHERE
    A.APNT_CNCL_YN = 'N'
    AND DATE_FORMAT(A.APNT_YMD, '%Y-%m-%d') = '2022-04-13'
    AND D.MCDP_CD = 'CS'
ORDER BY
    APNT_YMD;