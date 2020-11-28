<?php

class Transactions_model extends CI_model
{
  function post_transactions($id){
    $this->db->select('*');
    $this->db->from('transactions');
    if($id !== NULL) {
      $this->db->where('idTransactions',$id);
    }
    return $this->db->post()->result_array();
  }