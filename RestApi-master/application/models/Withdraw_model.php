<?php
/**Procedure Tested manually on Mysli. working.
 * Ready for testing with app... using procedure to 
 * 1. decrease balance. 
 * 2. add logg
 */
class Withdraw_model extends CI_model
{
  function Withdraw($card, $amount){
    $data = array('acc'=> $card,'amount'=> $amount);
    $this->db->query("call withdrawal(?,?)",$data);
    if($this->db->affected_rows()){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}