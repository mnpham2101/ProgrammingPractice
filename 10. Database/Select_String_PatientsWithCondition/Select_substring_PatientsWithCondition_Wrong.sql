# Write your MySQL query statement below
select patient_id, patient_name, conditions
from Patients
where substring(conditions, 1, 5) = 'DIAB1'             # wrong because conditions could be "ACNE DIAB100"