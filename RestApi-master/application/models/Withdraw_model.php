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
    $query=$this->db->query("call withdrawal(?,?)",$data);

    return $query->result();
  }
}