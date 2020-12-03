<?php
class Deposit_model extends CI_model
{
    function update_deposit($update_data){
    $this->db->query("CALL deposit(?,?)",$update_data);
    if($this->db->affected_rows()!==NULL){
      return $this->db->affected_rows();
    }
    else {
      return FALSE;
    }
  }
}