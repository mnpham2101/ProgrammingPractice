/* Write your MySQL or SQL query statement below */
select patient_id, patient_name, conditions
from Patients
where conditions like 'DIAB1%' or conditions like '% DIAB1%'            /* " " are not accepted in MSSQL, but in MySQL */