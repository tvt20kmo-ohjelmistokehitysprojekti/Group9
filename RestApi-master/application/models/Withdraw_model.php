<?php

class Withdraw_model extends CI_model
{

function withdraw($card, $amount){
        $data=array('acc'=>$card, 'amount'=>$amount);
        $this->db->query("CALL withdrawal(?,?)",$data);
        $result=$this->db->affected_rows();        
        if($result>0){
            return TRUE;
        }
        else{
            return FALSE;
        }

 

    }
}