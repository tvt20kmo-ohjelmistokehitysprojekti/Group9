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
  function balance ($client_id)
  {
  
    $this->db->select("Balance");
    $this->db->from("Account");
    $this->db->where('idClient',$client_id);
    /*return $query->affected_rows();*/
    return $this->db->get()->row("Balance");
  }
}