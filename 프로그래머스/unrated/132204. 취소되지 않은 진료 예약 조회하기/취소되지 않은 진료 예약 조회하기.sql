SELECT APNT_NO,
    PT_NAME,
    PT_NO,
    d.MCDP_CD,
    DR_NAME,
    APNT_YMD
FROM PATIENT p
    INNER JOIN APPOINTMENT a USING(PT_NO)
    INNER JOIN DOCTOR d ON a.MDDR_ID = d.DR_ID
WHERE APNT_YMD LIKE '2022-04-13%'
    AND APNT_CNCL_YN = 'N'
    AND d.MCDP_CD = 'CS'
ORDER BY APNT_YMD