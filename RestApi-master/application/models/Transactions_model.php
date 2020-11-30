
<?php
 
class Transactions_model extends CI_model
{
  function events ($client_id, $accType)
  {
    $call_procedure= "CALL get_acc_events(?,?)"; 
    $data=array('CID'=>$client_id, 'AType'=>$accType); //datamuuttujat joihin määritellään arvot
    $query=$this->db->query($call_procedure, $data);
  
    if($client_id !== NULL) 
    {
      //$this->db->where('CID',$client_id);
      echo "Löydetyt tapahtumat:";
    }
    /*return $query->affected_rows();*/
    return $query->result_array();
  }
}